package com;

public class testsm4 {


	public static void main(String[] args) {		
		String plaintext="01 23 45 67 89 ab cd ef fe dc ba 98 76 54 32 10";
         System.out.println("plaintext:  "+plaintext);

	     String stringkey="01 23 45 67 89 ab cd ef fe dc ba 98 76 54 32 10";
         System.out.println("stringkey:  "+stringkey);
         long MK[]=new long[4]; 

         long pIn[]=new long[4];

         long temp[]=new long[4];
         
         pIn=Fun.toLongarray(plaintext);
         MK=Fun.toLongarray(stringkey);
         
        temp=sm4.SM4ED(pIn, MK, 1);
        
        String ciphertext=Long.toHexString(temp[0]);
        for (int i = 1; i < temp.length; i++) {        	
			ciphertext=ciphertext.concat(Long.toHexString(temp[i]));
		}
        
        System.out.println("SM4加密密文为："+ciphertext);
        
        pIn=Fun.toLongarray(ciphertext);
        
        temp=sm4.SM4ED(pIn, MK, 0);
        
        ciphertext=Long.toHexString(temp[0]);
        
        for (int i = 1; i < temp.length; i++) {        	
			ciphertext=ciphertext.concat(Long.toHexString(temp[i]));
		}
        
        System.out.println("SM4解密明文为："+ciphertext);

         
	}

}
