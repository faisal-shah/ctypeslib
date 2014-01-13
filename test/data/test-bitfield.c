

// case 4 bytes on int32
struct bytes4 {
    unsigned int a1;
    unsigned int b1:9;
    unsigned int c1:9;
    unsigned int d1:9;
    char a2;
};



// case 4 bytes on int32
struct bytes4b {
    unsigned int b1:9;
    unsigned int c1:9;
    unsigned int d1:9;
};


// 3 bytes bitfield +1 char packed into a int32
// packed on 4 bytes by compiler. 
// But ctypes cannot put b1 in 3 bytes type
// so we force a2 in the bitfield
struct bytes3 { // should be 8 bytes
    unsigned int a1; // 0-31
    unsigned int b1:23; // 32-55 
    char a2; // 56-64 but python says 64-72
};


// case 3 bytes bitfield
struct bytes3b { // should be 8 bytes
    unsigned int b1:23; // 32-55 
};

// that works because a2 cant align in bitfield
struct bytes3c { 
    unsigned int b1:23; // 0-23
    // 9 bit align
    short a2; // 32-48 + pad
};


// case 2 bytes on int32
struct bytes2 {
    unsigned int a1;
    unsigned int b1:4;
    unsigned int c1:5;
    unsigned int d1:5;
    char a2;
};

// case 2 bytes on int32
struct bytes2b {
    unsigned int b1:4;
    unsigned int c1:5;
    unsigned int d1:5;
};

// case 1 byte on int32
struct byte1 {
    unsigned int b1:4;
    char a2;
};



// case 1 byte on int32
struct byte1b {
    unsigned int b1:4;
};


// packed by compiler in two bitfields a1,b1,c1 and d1
// force python to do the same
struct complex1 {
    unsigned char a1:1;
    unsigned char b1:7;
    unsigned int c1:1;
    unsigned int d1:31;
};


// packed by compiler in three bitfields 
// b1,c1,d1
// b2 alone
// c2, d2 together
// where we would have expected b2,c2,d2 together in int16
struct complex {
    unsigned int a1;
    unsigned int b1:4;
    unsigned int c1:10;
    unsigned int d1:2;
    char a2;
    unsigned int b2:4;
    unsigned int c2:10;
    unsigned long long d2:2;
    int h;
};

// packed by compiler in three bitfields 
// b1,c1,d1
// b2 alone
// c2, d2 together
// more or less expected
struct complex2 {
    unsigned int a1;
    unsigned int b1:4;
    unsigned int c1:10;
    unsigned int d1:2;
    char a2;
    unsigned int b2:4;
    unsigned int c2:10;
    unsigned long long d2:3;
    int h;
};

