import java.io.IOException;
import java.util.Scanner;
import com.fazecast.jSerialComm.*;

// Servo: TD-8325MG
// Microcontroller: RP2040

public class SerialCommandSender {
    public static void main(String[] args) {
        SerialPort serialPort = SerialPort.getCommPort("COM7");
        serialPort.setBaudRate(9600);
        serialPort.setComPortTimeouts(SerialPort.TIMEOUT_READ_BLOCKING, 1000, 0);

        if (!serialPort.openPort()) {
            System.out.println("Failed to open port.");
            return;
        }

        try {
            Thread.sleep(2000); // Wait for the connection to establish

            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter command ('f' for forward, 'b' for backward): ");
            String userInput = scanner.nextLine().toLowerCase();

            if (userInput.equals("f") || userInput.equals("b")) {
                sendCommand(serialPort, userInput);
            } else {
                System.out.println("Invalid command. Please enter 'f' or 'b'.");
            }

            scanner.close();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            serialPort.closePort();
            System.out.println("Serial connection closed.");
        }
    }

    private static void sendCommand(SerialPort serialPort, String command) {
        try {
            serialPort.getOutputStream().write(command.getBytes());
            serialPort.getOutputStream().flush();
            System.out.println("Sent command: " + command);
            Thread.sleep(500); // Wait a bit for the command to be processed
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
