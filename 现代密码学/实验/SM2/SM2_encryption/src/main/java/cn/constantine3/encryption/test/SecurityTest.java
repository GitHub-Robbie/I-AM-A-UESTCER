package cn.constantine3.encryption.test;

import cn.constantine3.encryption.utils.Util;
import cn.constantine3.encryption.utils.sm2.SM2EncDecUtils;
import cn.constantine3.encryption.utils.sm2.SM2KeyVO;

import java.io.IOException;
import java.util.Scanner;

public class SecurityTest {

    // 写死SM2公钥头，TODO
    public static final String SM2PubHardKeyHead = "3059301306072A8648CE3D020106082A811CCF5501822D034200";

    public static void main(String[] args) throws IOException {
        System.out.println("--产生SM2秘钥--:");
        SM2KeyVO sm2KeyVO = generateSM2Key();
        System.out.println("公钥:" + sm2KeyVO.getPubHexInSoft());
        System.out.println("私钥:" + sm2KeyVO.getPriHexInSoft());
        // 数据加密
        System.out.println("--测试加密开始--");
        // 输入原文
        System.out.print("请输入需要加密的字符串, 可包括空格: ");
        Scanner sc = new Scanner(System.in);
        String src = sc.nextLine();
        System.out.println("原文UTF-8转hex:" + Util.byteToHex(src.getBytes()));
        String SM2Enc = SM2Enc(sm2KeyVO.getPubHexInSoft(), src);
        System.out.println("密文:" + SM2Enc);
        String SM2Dec = SM2Dec(sm2KeyVO.getPriHexInSoft(), SM2Enc);
        System.out.println("解密:" + SM2Dec);
        System.out.println("--测试加密结束--");
    }

    // 公钥加密
    private static String SM2Enc(String pubKey, String src) {
        String encrypt = SM2EncDecUtils.encrypt(Util.hexStringToBytes(pubKey), src.getBytes());
        encrypt=encrypt.substring(2);
        return encrypt;
    }

    //私钥解密
    private static String SM2Dec(String priKey, String encryptedData) throws IOException {
        encryptedData="04"+encryptedData;
        byte[] decrypt = SM2EncDecUtils.decrypt(Util.hexStringToBytes(priKey), Util.hexStringToBytes(encryptedData));
        return new String(decrypt);
    }

    // 产生非对称秘钥
    private static SM2KeyVO generateSM2Key() {
        SM2KeyVO sm2KeyVO = SM2EncDecUtils.generateKeyPair();
        return sm2KeyVO;
    }
}
