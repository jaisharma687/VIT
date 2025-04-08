import io.pkts.Pcap;
import io.pkts.packet.IPPacket;
import io.pkts.packet.Packet;
import io.pkts.packet.TCPPacket;
import io.pkts.protocol.Protocol;

import java.io.IOException;
import java.util.concurrent.atomic.AtomicInteger;

public class PcapAnalyzer {
    public static void main(String[] args) {
        String pcapFile = "src/main/resources/chargen-tcp.pcap";

        try {
            System.out.println("Opening PCAP file: " + pcapFile);
            Pcap pcap = Pcap.openStream(pcapFile);
            System.out.println("PCAP file opened successfully");
            
            final AtomicInteger counter = new AtomicInteger();
            
            pcap.loop(packet -> {
                counter.incrementAndGet();
                System.out.println("Packet #" + counter.get() + " Protocol: " + packet.getProtocol());
                
                if (packet.hasProtocol(Protocol.TCP)) {
                    TCPPacket tcpPacket = (TCPPacket) packet.getPacket(Protocol.TCP);
                    IPPacket ipPacket = (IPPacket) tcpPacket.getParentPacket();

                    System.out.println("Source IP: " + ipPacket.getSourceIP());
                    System.out.println("Destination IP: " + ipPacket.getDestinationIP());
                    System.out.println("Source Port: " + tcpPacket.getSourcePort());
                    System.out.println("Destination Port: " + tcpPacket.getDestinationPort());

                    if (tcpPacket.getPayload() != null) {
                        byte[] payload = tcpPacket.getPayload().getArray();
                        if (payload != null && payload.length > 0) {
                            String data = new String(payload);
                            System.out.println("Payload: " + data);
                        } else {
                            System.out.println("Payload is empty");
                        }
                    } else {
                        System.out.println("No payload available");
                    }

                    System.out.println("---");
                }
                return true;
            });
            
            System.out.println("Total packets processed: " + counter.get());
            
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
