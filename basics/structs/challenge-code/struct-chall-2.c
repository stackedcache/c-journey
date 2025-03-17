#include <stdio.h> 

struct Packet {
    unsigned short source_port;
    unsigned short destination_port;
    unsigned int sequence_number;
    unsigned int ack_number;
    
    unsigned int header_len : 4;
    unsigned int reserved : 6;
    unsigned int urg_flag : 1;
    unsigned int ack_flag : 1;
    unsigned int psh_flag : 1;
    unsigned int rst_flag : 1;
    unsigned int syn_flag : 1;
    unsigned int fin_flag : 1;
    
    unsigned short window_size;
    unsigned short checksum;
    unsigned short urg_pointer;
};

int main(){
    struct Packet packet1 = {
        4560, // Source Port 
        443, // Dest Port 
        0, // Sequence Number 
        0, // ACK number 
        5, // Header Length
        0, // Reserved 
        0, // URG flag
        0, // ACK flag
        0, // PSH flag
        0, // RST flag
        1, // SYN flag
        0, // FIN flag
        5840, // Window size 
        0x84f7, // Checksum
        0 // URG pointer 
    };
    
    // Print the fields 
    printf("Source Port: %d\n", packet1.source_port);
    printf("Dest Port: %d\n", packet1.destination_port);
    printf("Sequence Number: %d\n", packet1.sequence_number);
    printf("Ack Number: %d\n", packet1.ack_number);
    printf("Header Length: %d\n", packet1.header_len);
    printf("Reserved: %d\n", packet1.reserved);
    printf("Urgent Flag: %d\n", packet1.urg_flag);
    printf("ACK Flag: %d\n", packet1.ack_flag);
    printf("PSH flag: %d\n", packet1.psh_flag);
    printf("RST flag: %d\n", packet1.rst_flag);
    printf("SYN flag: %d\n", packet1.syn_flag);
    printf("FIN flag: %d\n", packet1.fin_flag);
    printf("Window Size: %d\n", packet1.window_size);
    printf("Checksum: %d\n", packet1.checksum);
    printf("URG Pointer: %d\n", packet1.urg_pointer);

    return 0;
}

/* LEARNING NOTES 
    
    - Unsigned short in C is typically 16 bits, so we use this to save space where field is 16 bits.
    - The 16 is implied, so not needed in syntax (unsigned short soure_port : 16;)
    - In a real program, adding the standard size (unsigned short : 16, or unsigned int : 32) may cause compiler issues
    - You only need to add the bit value when using a non standard size.
*/
