import java.io.*;
import java.net.*;
import java.util.*;

/*
 * Class: Client
 * Purpose: Sends a name to the server and displays the converted string.
 */
public class Client {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        Socket s = new Socket("localhost", 5000);

        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        DataInputStream dis = new DataInputStream(s.getInputStream());

        System.out.print("Enter name: ");
        String name = sc.nextLine();

        dos.writeUTF(name);

        String result = dis.readUTF();

        System.out.println("Server: " + result);

        s.close();
        sc.close();
    }
}
