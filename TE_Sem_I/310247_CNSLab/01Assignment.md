### Assignment No 1

**Aim:** To Setup a wired LAN using Layer 2 Switch and then IP switch of minimum four
computers.

**Theory:**
<https://youtu.be/ehT-wihbR58?si=ovQ3VE6n3wsfsiyL>

1. What type of cables are used in our labs and why?

- Twisted Pair Cable: Unshielded Twisted Pair (UTP): Commonly used in Ethernet networks. It has pairs of insulated copper wires twisted together. UTP cables are often used for connecting computers to Ethernet networks.
- Shielded Twisted Pair (STP): Similar to UTP, but with additional shielding to reduce electromagnetic interference. It's used in environments where there might be higher levels of interference.
- Coaxial Cable: Consists of a central copper conductor surrounded by a layer of insulation, a metallic shield, and an outer insulating layer. Coaxial cables are often used for cable television (CATV) and broadband internet connections
- Fiber Optic Cable: Uses thin strands of glass or plastic (fibers) to transmit data using light signals. Fiber optic cables offer high bandwidth and are immune to electromagnetic interference. They are commonly used for long-distance and high-speed data transmission.
- Ethernet Cables: Commonly used in local area networks (LANs) for connecting devices like computers, printers, and switches. Ethernet cables can be either twisted pair (e.g., Cat5e, Cat6, Cat6a) or fiber optic.

2. What is the topology of a lab in PICT?

- The specific topology can vary based on the design preferences and requirements of the network administrator, but a common choice for small to medium-sized computer labs is a **star topology**.
- In a star topology: All the computers (in this case, the 25 PCs) are connected to a central network switch. Each PC has its own dedicated connection to the switch.
- The switch manages the traffic between the PCs, and any communication between two PCs goes through the switch.
- If a PC needs to communicate with another PC, the data is sent from the source PC to the switch and then forwarded to the destination PC.

3. What is topology of PICT?
we can infer some aspects of the network topology at Pune Institute of Computer Technology (PICT). While the exact details may not be fully specified, the available information suggests a combination of topologies based on different requirements within the institution. Here are some elements that contribute to the overall network topology:
Campus-Wide Connectivity: PICT likely employs a campus-wide network to connect various buildings and departments. The use of fiber backbone (spanning over 17 km) indicates a distributed network infrastructure across the campus.
Switching Infrastructure: The use of more than 55 manageable Fast Ethernet switches suggests a combination of switches distributed throughout the campus. This aligns with a distributed switching architecture, potentially using a combination of access, distribution, and core switches.
Lab-Specific Connectivity: Dedicated labs for internet usage equipped with 50+ machines each imply localized network setups, possibly organized in a star or bus topology within these specific areas.
Wi-Fi Connectivity: The provision of Wi-Fi across the campus suggests the presence of wireless access points (APs) distributed strategically. The use of a dedicated Wi-Fi controller with user authentication indicates centralized management.
Server Room: The central administration air-conditioned server room with UPS backup suggests a central point for critical network infrastructure, potentially housing servers, routers, and other networking equipment.
Internet Connectivity: The information indicates redundant internet providers (Reliance Communication Ltd. and Paradise Telecom Pvt. Ltd.) and a total bandwidth of 600 Mbps, ensuring 1:1 connectivity. This may involve load balancing and failover mechanisms.
Departmental and Unit Connectivity: The mention that all departments and units are connected to the internet with more than 55 Cisco Fast Ethernet switches indicates a well-connected network grid. The use of 1 Gbps LAN connectivity to staff rooms and departments further supports a robust internal network.
Email and Internet Facilities: Availability of internet facilities in various areas such as staff rooms, admin offices, account offices, library, hostels, canteen, and open campus areas suggests an extensive network topology reaching every corner of the institute. While the specific topology details are not explicitly stated, the information provided suggests a combination of star, distributed switching, and potentially hierarchical (core-distribution-access) topologies. The use of redundant links, centralized server rooms, and widespread connectivity across the campus reflect a well-designed and resilient network infrastructure at PICT

4. What is bandwidth available in PICT Labs?
 The provided information mentions that the labs at PICT are equipped with a dedicated lab for internet usage, and the internet connectivity is provided through two providers: Reliance Communication Ltd. (400 Mbps) and Paradise Telecom Pvt. Ltd. (200 Mbps). The total available bandwidth is 600 Mbps, ensuring 1:1 connectivity at all times.

5. What is supported data rate by Ethernet 802.3?
Ethernet 802.3, which is a widely used standard for wired LANs, supports different data rates. Common data rates for Ethernet include 10 Mbps (Ethernet), 100 Mbps (Fast Ethernet), 1 Gbps (Gigabit Ethernet), 10 Gbps, 25 Gbps, 40 Gbps, and 100 Gbps. The specific data rate depends on the version of Ethernet and the hardware in use.

6. What is the difference between Hub, Router and a switch?
**Hub:** Hubs operate at the physical layer of the OSI model and simply broadcast data to all devices connected to them. They lack intelligence and don't filter traffic, leading to a less efficient use of bandwidth. Hubs are considered outdated in modern networks.
**Router:** Routers operate at the network layer and are responsible for routing data between different networks. They use logical addressing (IP addresses) to make decisions about forwarding data packets. Routers connect networks and provide a level of security by separating broadcast domains.
**Switch:** Switches operate at the data link layer and use MAC addresses to forward data only to the device for which it is intended. They are more intelligent than hubs and provide better bandwidth efficiency. Switches create separate collision domains for each port, improving network performance.
7. What type of switches are used in our PICT labs?

- Yet To answer

8. **Wi-Fi is a standard, so is Ethernet. Identify the name of the standard for each of these communications protocols.**
**Wi-Fi:** The standard for Wi-Fi is defined by the Institute of Electrical and Electronics Engineers (IEEE) 802.11 family of standards. Common Wi-Fi standards include 802.11b, 802.11g, 802.11n, 802.11ac, and 802.11ax. These standards define the specifications for wireless local area networking (WLAN) communication.
**Ethernet:** The standard for Ethernet is defined by the IEEE 802.3 family of standards. Common Ethernet standards include 10BASE-T, 100BASE-TX, 1000BASE-T (Gigabit Ethernet), 10GBASE-T, and others. These standards specify the characteristics and requirements for wired LAN communication.

**9. Who can contribute to Internet standards?**
Internet standards are developed and maintained by various organizations, with contributions from individuals, experts, and professionals in the field. The key organization responsible for developing and defining standards for the Internet is the Internet Engineering Task Force (IETF). The IETF is an open international community of network designers, operators, vendors, and researchers concerned with the evolution and smooth operation of the Internet architecture.
The Internet Society (ISOC) also plays a role in the development and promotion of Internet standards. Additionally, various standardization bodies, such as the International Telecommunication Union (ITU), contribute to the development of global communication standards.
Contributions to Internet standards are typically made by professionals and experts who participate in working groups, discussions, and committees within these organizations. The standards development process is open, collaborative, and involves input from a diverse range of stakeholders.

10. **write IEEE standards for-**
  Ethernet 802.3
  Wi-Fi -  802.11
  Token ring - 802.5
  Wimax - 802.015
  Bluetooth: 802.15.4

11.**What is the difference between a hub and a switch?**

| Feature                  | Hub                                      | Switch                                   |
|--------------------------|------------------------------------------|------------------------------------------|
| **Layer of Operation**   | Physical Layer                           | Data Link Layer                          |
| **Functionality**        | Broadcasts data to all connected devices | Forwards data only to the intended device|
| **Traffic Management**   | No traffic management, shared bandwidth  | Manages traffic, provides dedicated bandwidth to each port |
| **Collision Domain**     | Shared collision domain                  | Individual collision domain per port     |
| **Efficiency**           | Less efficient due to collisions         | More efficient as it minimizes collisions|
| **Address Learning**     | No address learning                      | Learns MAC addresses to make forwarding decisions |
| **Data Transmission**    | Half-duplex                              | Full-duplex or half-duplex, depending on the model |
| **Cost**                 | Typically less expensive                 | Can be more expensive, especially for managed switches |
| **Use Case**             | Less suitable for large or busy networks | Suitable for larger networks, provides better performance and scalability |
