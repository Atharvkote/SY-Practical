// Main class to test the hybrid inheritance structure
public class HybridInheritnace {

    // Base class representing a person
static class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public void introduce() {
        System.out.println("Hello, my name is " + name + " and I am " + age + " years old.");
    }
}

// Interface for medical staff duties
interface MedicalDuties {
    void provideCare();
    void attendEmergency();
}

// Interface for administrative duties
interface AdministrativeDuties {
    void manageAppointments();
    void answerCalls();
}

// Doctor class extending Person and implementing MedicalDuties
static class Doctor extends Person implements MedicalDuties {
    private String specialization;
    private double salary;

    public Doctor(String name, int age, String specialization, double salary) {
        super(name, age);
        this.specialization = specialization;
        this.salary = salary;
    }

    public String getSpecialization() {
        return specialization;
    }

    public double getSalary() {
        return salary;
    }

    @Override
    public void provideCare() {
        System.out.println(getName() + " (Doctor - " + specialization + ") is diagnosing and treating patients.");
    }

    @Override
    public void attendEmergency() {
        System.out.println(getName() + " is handling an emergency case in the ER.");
    }

    public void prescribeMedicine() {
        System.out.println(getName() + " is prescribing medicine to a patient.");
    }

    public void work() {
        System.out.println(getName() + " is consulting patients in the hospital.");
    }
}

// Nurse class extending Person and implementing MedicalDuties
static class Nurse extends Person implements MedicalDuties {
    private String shift;
    private double salary;

    public Nurse(String name, int age, String shift, double salary) {
        super(name, age);
        this.shift = shift;
        this.salary = salary;
    }

    public String getShift() {
        return shift;
    }

    public double getSalary() {
        return salary;
    }

    @Override
    public void provideCare() {
        System.out.println(getName() + " (Nurse) is assisting in patient care and administering medication.");
    }

    @Override
    public void attendEmergency() {
        System.out.println(getName() + " is rushing to assist in an emergency.");
    }

    public void assistDoctor() {
        System.out.println(getName() + " is assisting the doctor in surgery.");
    }

    public void work() {
        System.out.println(getName() + " is working during the " + shift + " shift.");
    }
}

// Receptionist class extending Person and implementing AdministrativeDuties
static class Receptionist extends Person implements AdministrativeDuties {
    private int workingHours;
    private double salary;

    public Receptionist(String name, int age, int workingHours, double salary) {
        super(name, age);
        this.workingHours = workingHours;
        this.salary = salary;
    }

    public int getWorkingHours() {
        return workingHours;
    }

    public double getSalary() {
        return salary;
    }

    @Override
    public void manageAppointments() {
        System.out.println(getName() + " (Receptionist) is scheduling and managing doctor appointments.");
    }

    @Override
    public void answerCalls() {
        System.out.println(getName() + " is answering patient inquiries over the phone.");
    }

    public void work() {
        System.out.println(getName() + " is handling the front desk for " + workingHours + " hours today.");
    }
}

// Hybrid ReceptionistDoctor class that acts as both a doctor and receptionist
static class ReceptionistDoctor extends Doctor implements AdministrativeDuties {
    public ReceptionistDoctor(String name, int age, String specialization, double salary) {
        super(name, age, specialization, salary);
    }

    @Override
    public void manageAppointments() {
        System.out.println(getName() + " (Doctor & Receptionist) is treating patients and managing appointments.");
    }

    @Override
    public void answerCalls() {
        System.out.println(getName() + " is answering patient queries and booking appointments.");
    }
}

// Hybrid ReceptionistNurse class that acts as both a nurse and receptionist
static class ReceptionistNurse extends Nurse implements AdministrativeDuties {
    public ReceptionistNurse(String name, int age, String shift, double salary) {
        super(name, age, shift, salary);
    }

    @Override
    public void manageAppointments() {
        System.out.println(getName() + " (Nurse & Receptionist) is assisting doctors and managing schedules.");
    }

    @Override
    public void answerCalls() {
        System.out.println(getName() + " is answering patient inquiries.");
    }
}

    public static void main(String[] args) {
        Doctor doctor = new Doctor("Dr. Smith", 45, "Cardiology", 120000);
        Nurse nurse = new Nurse("Nurse Emily", 30, "Night", 55000);
        Receptionist receptionist = new Receptionist("Mr. Brown", 35, 8, 40000);
        ReceptionistDoctor receptionDoctor = new ReceptionistDoctor("Dr. White", 50, "Neurology", 130000);
        ReceptionistNurse receptionNurse = new ReceptionistNurse("Nurse Anna", 28, "Day", 50000);

        System.out.println("\n=== Doctor's Work ===");
        doctor.introduce();
        doctor.provideCare();
        doctor.attendEmergency();
        doctor.prescribeMedicine();
        doctor.work();

        System.out.println("\n=== Nurse's Work ===");
        nurse.introduce();
        nurse.provideCare();
        nurse.attendEmergency();
        nurse.assistDoctor();
        nurse.work();

        System.out.println("\n=== Receptionist's Work ===");
        receptionist.introduce();
        receptionist.manageAppointments();
        receptionist.answerCalls();
        receptionist.work();

        System.out.println("\n=== Hybrid Receptionist-Doctor ===");
        receptionDoctor.introduce();
        receptionDoctor.provideCare();
        receptionDoctor.attendEmergency();
        receptionDoctor.manageAppointments();
        receptionDoctor.answerCalls();

        System.out.println("\n=== Hybrid Receptionist-Nurse ===");
        receptionNurse.introduce();
        receptionNurse.provideCare();
        receptionNurse.manageAppointments();
        receptionNurse.answerCalls();
    }
}