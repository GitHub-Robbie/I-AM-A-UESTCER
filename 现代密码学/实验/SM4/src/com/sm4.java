package com;

public class sm4 {
    public static final int[][] Sbox = {
            {0xd6, 0x90, 0xe9, 0xfe, 0xcc, 0xe1, 0x3d, 0xb7, 0x16, 0xb6, 0x14, 0xc2, 0x28, 0xfb, 0x2c, 0x05},
            {0x2b, 0x67, 0x9a, 0x76, 0x2a, 0xbe, 0x04, 0xc3, 0xaa, 0x44, 0x13, 0x26, 0x49, 0x86, 0x06, 0x99},
            {0x9c, 0x42, 0x50, 0xf4, 0x91, 0xef, 0x98, 0x7a, 0x33, 0x54, 0x0b, 0x43, 0xed, 0xcf, 0xac, 0x62},
            {0xe4, 0xb3, 0x1c, 0xa9, 0xc9, 0x08, 0xe8, 0x95, 0x80, 0xdf, 0x94, 0xfa, 0x75, 0x8f, 0x3f, 0xa6},
            {0x47, 0x07, 0xa7, 0xfc, 0xf3, 0x73, 0x17, 0xba, 0x83, 0x59, 0x3c, 0x19, 0xe6, 0x85, 0x4f, 0xa8},
            {0x68, 0x6b, 0x81, 0xb2, 0x71, 0x64, 0xda, 0x8b, 0xf8, 0xeb, 0x0f, 0x4b, 0x70, 0x56, 0x9d, 0x35},
            {0x1e, 0x24, 0x0e, 0x5e, 0x63, 0x58, 0xd1, 0xa2, 0x25, 0x22, 0x7c, 0x3b, 0x01, 0x21, 0x78, 0x87},
            {0xd4, 0x00, 0x46, 0x57, 0x9f, 0xd3, 0x27, 0x52, 0x4c, 0x36, 0x02, 0xe7, 0xa0, 0xc4, 0xc8, 0x9e},
            {0xea, 0xbf, 0x8a, 0xd2, 0x40, 0xc7, 0x38, 0xb5, 0xa3, 0xf7, 0xf2, 0xce, 0xf9, 0x61, 0x15, 0xa1},
            {0xe0, 0xae, 0x5d, 0xa4, 0x9b, 0x34, 0x1a, 0x55, 0xad, 0x93, 0x32, 0x30, 0xf5, 0x8c, 0xb1, 0xe3},
            {0x1d, 0xf6, 0xe2, 0x2e, 0x82, 0x66, 0xca, 0x60, 0xc0, 0x29, 0x23, 0xab, 0x0d, 0x53, 0x4e, 0x6f},
            {0xd5, 0xdb, 0x37, 0x45, 0xde, 0xfd, 0x8e, 0x2f, 0x03, 0xff, 0x6a, 0x72, 0x6d, 0x6c, 0x5b, 0x51},
            {0x8d, 0x1b, 0xaf, 0x92, 0xbb, 0xdd, 0xbc, 0x7f, 0x11, 0xd9, 0x5c, 0x41, 0x1f, 0x10, 0x5a, 0xd8},
            {0x0a, 0xc1, 0x31, 0x88, 0xa5, 0xcd, 0x7b, 0xbd, 0x2d, 0x74, 0xd0, 0x12, 0xb8, 0xe5, 0xb4, 0xb0},
            {0x89, 0x69, 0x97, 0x4a, 0x0c, 0x96, 0x77, 0x7e, 0x65, 0xb9, 0xf1, 0x09, 0xc5, 0x6e, 0xc6, 0x84},
            {0x18, 0xf0, 0x7d, 0xec, 0x3a, 0xdc, 0x4d, 0x20, 0x79, 0xee, 0x5f, 0x3e, 0xd7, 0xcb, 0x39, 0x48}};
    public static final long[] FK = {0xa3B1BAC6L,0x56AA3350L,0x677D9197L,0x00B27022DCL};

    public static final long[] CK={0x00070e15L,0x1c232a31L,0x383f464dL,0x545b6269L,0x70777e85L,0x8c939aa1L,
            0xa8afb6bdL,0xc4cbd2d9L,0xe0e7eef5L,0xfc030a11L,0x181f262dL,0x343b4249L,0x50575e65L,0x6c737a81L,
            0x888f969dL,0xa4abb2b9L,0xc0c7ced5L,0xdce3eaf1L,0xf8ff060dL,0x141b2229L,0x30373e45L,0x4c535a61L,
            0x686f767dL,0x848b9299L,0xa0a7aeb5L,0xbcc3cad1L,0xd8dfe6edL,0xf4fb0209L,0x10171e25L,0x2c333a41L,
            0x484f565dL,0x646b7279L};

    //left shift//test done
    public static long LS(long In, int Num) {
        //#define LS(x,y) ((x<<y)|(x>>(32-y)))
        long Tmp;
        Tmp = (In << Num ) & 0xFFFFFFFFL;
        Tmp|= (In >>> (32 - Num));
        Tmp &= 0xFFFFFFFF;
        return Tmp;
    }

    //L transform function//test done
    public static long TransL(long Tmp) {
        return Tmp ^ LS(Tmp, 2) ^ LS(Tmp, 10)^ LS(Tmp, 18)^ LS(Tmp, 24);
    }

    //L transform(for key exp)//test done
    public static long TransLh(long Tmp) {
        return Tmp ^ LS(Tmp, 13) ^ LS(Tmp, 23);
    }

    //Sbox//test done
    public static int Sub(int Tmp) {
        return Sbox[Tmp>>4][Tmp&0xF];
    }
    //long sbox transform//test done
    public static long Subl(long In) {
        long Tmp = 0;
        Tmp += (long)Sub((int)(In >> 24) & 0xFF);
        Tmp <<= 8;
        Tmp += (long)Sub((int)(In >> 16) & 0xFF);
        Tmp <<= 8;
        Tmp += (long)Sub((int)(In >> 8 ) & 0xFF);
        Tmp <<= 8;
        Tmp += (long)Sub((int)In & 0xFF);
        return Tmp;
    }

    //L transform
    public static long TransT(long Tmp) {
        return TransL(Subl(Tmp));
    }

    //L transform for key
    public static long TransTh(long In) {
        return TransLh(Subl(In));
    }

    public static long Loop(long pIn0, long pIn1, long pIn2, long pIn3, long rk)
    {
        return pIn0 ^ TransT(pIn1 ^ pIn2 ^ pIn3 ^ rk);
    }

    //key generator
    public static long[] KeyExp( long MK[])
    {
        int a1=0;
        long[] TK= new long[4];
        long[] rk = new long[32];

        for(a1 = 0; a1 < 4; a1++)
            TK[a1] = MK[a1] ^ (FK[a1]);

        rk[0] = TK[0] ^ TransTh(TK[1] ^ TK[2] ^ TK[3] ^ CK[0]);
        rk[1] = TK[1] ^ TransTh(TK[2] ^ TK[3] ^ rk[0] ^CK[1]);
        rk[2] = TK[2] ^ TransTh(TK[3] ^ rk[0] ^ rk[1] ^ CK[2]);
        rk[3] = TK[3] ^ TransTh(rk[0] ^ rk[1] ^ rk[2] ^ CK[3]);
        for(a1 = 4; a1 < 32; a1++)
        {
            rk[a1]=rk[a1 - 4]  ^TransTh(rk[a1 - 3] ^ rk[a1 - 2] ^ rk[a1 - 1] ^ CK[a1]);
        }
        return rk;
    }

    //SM4加解密
    public static long[] SM4ED(long pIn[], long MK[], int iEnc)
    {
        long[] rk=new long[32];
        long Tmp;
        long[] plain=null;
        int a1;

        rk = KeyExp(MK);

        System.out.println("rk: ");
        if (1==iEnc) {

            for (int i = 0; i < rk.length; i++) {
                System.out.println(i+"  "+Long.toHexString(rk[i]));
            }

        }else {
            for (int i = 0; i < rk.length; i++) {
                System.out.println(i+"  "+Long.toHexString(rk[31-i]));
            }
        }


        plain= new long[4];
        for(a1 = 0; a1 < 4; a1++)
            plain[a1] = pIn[a1];

        if(iEnc == 1)
        {
            for(a1 = 0; a1 < 32; a1++)
            {
                Tmp = Loop(plain[0], plain[1], plain[2], plain[3], rk[a1]);
                plain[0] = plain[1];
                plain[1] = plain[2];
                plain[2] = plain[3];
                plain[3] = Tmp;
            }
        }
        else
        {
            for(a1 = 0; a1 < 32; a1++)
            {
                Tmp = Loop(plain[0], plain[1], plain[2], plain[3], rk[31 - a1]);
                plain[0] = plain[1];
                plain[1] = plain[2];
                plain[2] = plain[3];
                plain[3] = Tmp;
            }
        }
        Tmp = plain[0];
        plain[0] = plain[3];
        plain[3] = Tmp;
        Tmp = plain[1];
        plain[1] = plain[2];
        plain[2] = Tmp;
        return plain;
    }

    public static long[] KeyReverseSM4( long rk[])
    {
        int a1;
        long TK[], MK[];
        TK = new long[4];
        MK = new long[4];
        TK[3] = rk[3] ^ TransTh(rk[0] ^ rk[1] ^ rk[2] ^ CK[3]);
        TK[2] = rk[2] ^ TransTh(TK[3] ^ rk[0] ^ rk[1] ^ CK[2]);
        TK[1] = rk[1] ^ TransTh(TK[2] ^ TK[3] ^ rk[0] ^ CK[1]);
        TK[0] = rk[0] ^ TransTh(TK[1] ^ TK[2] ^ TK[3] ^ CK[0]);
        for(a1 = 0; a1 < 4; a1++)
            MK[a1] =TK[a1] ^ FK[a1];
        return MK;
    }

    //key generator
    public static long[] KeyReverse( long rk[])
    {
        int a1;
        long K[], MK[];
        K = new long[4];
        MK = new long[4];
        long Tmp=0;
        for (int i = 27; i >=0; i--) {
            Tmp = rk[0] ^ TransTh(rk[1]^ rk[2] ^ rk[3]^ CK[i+4]);
            rk[0]= rk[1];
            rk[1]= rk[2];
            rk[2]= rk[3];
            rk[3]= Tmp;
        }
        //顺序调换成加密顺序
        Tmp= rk[3];
        rk[3]=rk[0];
        rk[0]=Tmp;
        Tmp= rk[2];
        rk[2]=rk[1] ;
        rk[1]= Tmp;

        K[3] = rk[3] ^ TransTh(rk[0] ^ rk[1] ^ rk[2] ^ CK[3]);
        K[2] = rk[2] ^ TransTh(K[3]^ rk[0] ^ rk[1] ^ CK[2]);
        K[1] = rk[1] ^ TransTh(K[2]^ K[3]^ rk[0] ^ CK[1]);
        K[0] = rk[0] ^ TransTh(K[1]^ K[2]^ K[3] ^ CK[0]);
        for(a1 = 0; a1 < 4; a1++)
            MK[a1] =K[a1] ^ FK[a1];
        return MK;
    }

    //key generator
    public static long[] KeyExp2( long rk2[])
    {

        int a1=0;
        long[]  rk=new long[32];
        for (int i = 0; i < 4; i++) {
            rk[i]=rk2[i];
        }

        for(a1 = 4; a1 < 32; a1++)
        {
            rk[a1] =rk[a1 - 4] ^TransTh(rk[a1 - 3] ^ rk[a1 - 2] ^ rk[a1 - 1] ^ CK[35-a1]);
        }

        System.out.println("sm4轮密钥为：");
        for (int i = 0; i < rk.length; i++) {
            System.out.println("rk"+i+":  "+Long.toHexString(rk[i]));
        }

        return rk;
    }



    //线性变换逆变换
    public static long invTransL(long Tmp) {
        return Tmp ^ LS(Tmp, 2) ^ LS(Tmp, 4)^ LS(Tmp, 8)^ LS(Tmp, 12)^ LS(Tmp, 14) ^ LS(Tmp, 16)^ LS(Tmp, 18)^ LS(Tmp, 22)^ LS(Tmp, 24) ^ LS(Tmp, 30);
    }

    //一轮加密
    public static long[] oneloop(String p,long rk,int round){

        long[] plain=new long[4];
        plain=Fun.toLongarray(p);
        long Tmp=0;
        Tmp = Loop(plain[0], plain[1], plain[2], plain[3], rk);
        plain[0] = plain[1];
        plain[1] = plain[2];
        plain[2] = plain[3];
        plain[3] = Tmp;

        if(32==round){
            Tmp = plain[0];
            plain[0] = plain[3];
            plain[3] = Tmp;
            Tmp = plain[1];
            plain[1] = plain[2];
            plain[2] = Tmp;
        }
        return plain;
    }

    //一轮解密
    public static long[] oneloopdc(String p,long rk,int round){

        long[] cipher=new long[4];
        long[] plain=new long[4];
        cipher=Fun.toLongarray(p);
        long Tmp=0;
        if (32==round) {
            Tmp=cipher[0]^TransT(cipher[1]^ cipher[2]^cipher[3]^rk);
            plain[0] = Tmp;
            plain[1] = cipher[3];
            plain[2] = cipher[2];
            plain[3] = cipher[1];

        }

        if (32!=round) {
            Tmp=cipher[3]^TransT(cipher[0]^ cipher[1]^cipher[2]^rk);
            plain[0] = Tmp;
            plain[1] = cipher[0];
            plain[2] = cipher[1];
            plain[3] = cipher[2];
        }

        return plain;
    }

}
