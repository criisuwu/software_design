#ifndef SISTEMA_H
#define SISTEMA_H

#include <sqlite3.h>
#include <memory>
#include <vector>
#include <algorithm>
#include "User.h"
#include "Patient.h"
#include "Doctor.h"
#include "Admin.h"
#include "Robot.h"

/**
 * @class Sistema
 * @brief Clase principal encargada de gestionar el sistema, incluyendo la base de datos,
 *        el inicio de sesión, registro de usuarios y administración de robots.
 * 
 * Esta clase implementa el patrón Singleton para asegurar que solo exista una instancia global
 * del sistema. Permite interactuar con la base de datos SQLite, registrar y autenticar usuarios,
 * así como administrar las funcionalidades relacionadas con los robots.
 */

class Sistema {
private:
    /**
     * @brief Instancia única del sistema (patrón Singleton).
     */
    static Sistema* instance;
    /**
     * @brief Puntero al objeto de la base de datos SQLite.
     */
    sqlite3* db;
    /**
     * @brief Lista de robots administrados por el sistema.
     */
    std::vector<std::shared_ptr<Robot>> robots;
    /**
     * @brief Constructor privado
     */
    Sistema();
    /**
     * @brief Prohibe copiar la instancia
     */
    Sistema(const Sistema&) = delete;
    /**
     * @brief Prohibe la asignacion de la instancia
     */
    Sistema& operator=(const Sistema&) = delete;
   
    
public:
    /**
     * @brief Destructor del sistema.
     * 
     * Libera la memoria asociada y cierra la conexión con la base de datos.
     */
    ~Sistema();
    
    /**
     * @brief Obtiene la instancia única del sistema (Singleton).
     * 
     * Si la instancia aún no existe, la crea automáticamente.
     * 
     * @return Referencia a la instancia única del sistema.
     */
    static Sistema& getInstance() {
        if (!instance) instance = new Sistema();
        return *instance;
    }
    
    // ======================================================
    // Gestión de Base de Datos
    // ======================================================

    /**
     * @brief Conecta el sistema a la base de datos SQLite.
     * 
     * @return true si la conexión fue exitosa.
     * @return false si ocurrió un error al abrir la base de datos.
     * @throws DatabaseError Si SQLite devuelve un error de ejecución.
     */
    bool connectDatabase();
    /**
     * @brief Registra un nuevo usuario en la base de datos.
     * 
     * @param username Nombre de usuario.
     * @param password Contraseña del usuario.
     * @param role Rol del usuario (e.g., "doctor", "patient", "admin").
     * @param name Nombre completo del usuario (opcional).
     * @param email Correo electrónico del usuario (opcional).
     * @param specialty Especialidad del doctor si aplica (opcional).
     * @param telephone Teléfono del usuario si aplica (opcional).
     * 
     * @return true si el registro fue exitoso.
     * @return false si el usuario no pudo registrarse.
     * 
     * @throws DatabaseError Si ocurre un error en la ejecución de la consulta SQL.
     */
    bool registerUser(const std::string& username, const std::string& password, const std::string& role,
                     const std::string& name = "", const std::string& email = "", 
                     const std::string& specialty = "", const std::string& telephone = "");
    
    /**
     * @brief Autentica un usuario mediante sus credenciales.
     * 
     * @param username Nombre de usuario.
     * @param password Contraseña del usuario.
     * 
     * @return Puntero único al objeto User correspondiente al rol detectado.
     * 
     * @throws InvalidCredentialsError Si el usuario o la contraseña no coinciden.
     * @throws DatabaseError Si ocurre un error al consultar la base de datos.
     */
    std::unique_ptr<User> loginUser(const std::string& username, const std::string& password);
    
    // ======================================================
    // Gestión de Robots
    // ======================================================

    /**
     * @brief Inicializa una cantidad específica de robots dentro del sistema.
     * 
     * @param count Cantidad de robots a crear.
     */
    void initializeRobots(int count);
    /**
     * @brief Muestra el estado actual de todos los robots en el sistema.
     */
    void showRobotsStatus() const;
    /**
     * @brief Asigna una tarea a un robot específico.
     * 
     * @param robotId ID del robot.
     * @param seconds Duración estimada de la tarea en segundos.
     * @param taskType Tipo de tarea asignada.
     * 
     * @throws std::out_of_range Si el robotId no corresponde a ningún robot.
     */
    void assignRobotTask(int robotId, int seconds, const std::string& taskType);
    /**
     * @brief Asigna una tarea al primer robot disponible.
     * 
     * @param seconds Duración de la tarea en segundos.
     * @param taskType Tipo de tarea.
     * 
     * @throws std::runtime_error Si no hay robots disponibles.
     */
    void assignAnyRobot(int seconds, const std::string& taskType);
    /**
     * @brief Libera un robot que haya terminado su trabajo.
     * 
     * @param robotId ID del robot a liberar.
     * 
     * @throws std::out_of_range Si el robotId es inválido.
     */
    void freeRobot(int robotId);
    
    // ======================================================
    // Funcionalidades Administrativas
    // ======================================================

    /**
     * @brief Obtiene la lista de doctores registrados.
     * 
     * @return Vector de punteros a objetos User con rol de doctor.
     */
    std::vector<std::shared_ptr<User>> getDoctorsList() const;
    /**
     * @brief Obtiene la lista completa de usuarios del sistema.
     * 
     * @return Vector de punteros a objetos User.
     */
    std::vector<std::shared_ptr<User>> getAllUsers() const;
    /**
     * @brief Asigna un horario laboral a un médico.
     * 
     * @param idDoctor ID del médico.
     * @param day Día asignado.
     * @param start Hora de inicio.
     * @param end Hora de fin.
     * 
     * @return true si el horario fue asignado correctamente.
     * 
     * @throws DatabaseError Si ocurre un error al ejecutar la consulta SQL.
     */
    bool assignScheduleToDoctor(int idDoctor, const std::string& day,
                            const std::string& start, const std::string& end);

};

#endif