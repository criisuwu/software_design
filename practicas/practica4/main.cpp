#include <iostream>
#include <memory>
#include "imports/Administrator.h"
#include "imports/Notification.h"
#include "imports/Schedule.h"
#include "imports/Appointment.h"


// Falta crear un paciente y verificar que funcione pero tengo un error en la clase Patient
int main() {
    std::cout << "===== SISTEMA DE GESTIÓN HOSPITALARIA =====" << std::endl;

    // Con esto creo un administrador
    std::unique_ptr<Administrator> admin = std::make_unique<Administrator>(
        "A001", "adminUser", "1234", "555-1234", "admin@hospital.com", "Dr. Morales"
    );

    //Verifico que la clase administrador funciona
    std::cout << "\n--- Datos del Administrador ---" << std::endl;
    admin->displayInfo();
    admin->assignSpeciality("Cardiología");
    admin->manageSchedule();
    admin->manageCensus();

    //Creo una notificacion
    std::unique_ptr<Notification> notif = std::make_unique<Notification>(
        "Cita confirmada para el paciente Juan Pérez", true
    );

    //Verifico que la clase Notification funciona
    std::cout << "\n--- Notificación ---" << std::endl;
    notif->displayNotification();
    notif->sendNotification();
    notif->changeState(false);
    notif->displayNotification();

    // Creo un horario
    std::unique_ptr<Schedule> schedule = std::make_unique<Schedule>(
        10, "Cita con el Dr. García - Revisión general"
    );

    //Verifico que la clase horario funciona
    std::cout << "\n--- Horario ---" << std::endl;
    schedule->displaySchedule();
    schedule->setHour(11);
    schedule->setAppointment("Cita con el Dr. López - Pediatría");
    schedule->showInfo();

    // Creo una cita
    std::unique_ptr<Appointment> appointment = std::make_unique<Appointment>(
        "2025-11-05", "Consultorio 3", "Chequeo general"
    );

    //Verificacion de que la clase Appointment funciona
    std::cout << "\n--- Cita ---" << std::endl;
    appointment->displayAppointment();
    appointment->seeAppointment();
    appointment->confirmAppointment();
    appointment->moveAppointment("2025-11-12");
    appointment->changeStatusAppointment();
    appointment->cancelAppointment();
    return 0;
}


// TODO: Faltan comprobar un par de cosas con un main mas elavorado