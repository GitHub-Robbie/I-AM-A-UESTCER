package cn.constantine3.encryption.utils;

import java.math.BigInteger;

public class Util {

    /**
     * 字节数组转换为十六进制字符串
     *
     * @param b byte[] 需要转换的字节数组
     * @return String 十六进制字符串
     */
    public static String byteToHex(byte b[]) {
        if (b == null) {
            throw new IllegalArgumentException(
                    "Argument b ( byte array ) is null! ");
        }
        String hs = "";
        String stmp = "";
        for (int n = 0; n < b.length; n++) {
            stmp = Integer.toHexString(b[n] & 0xff);
            if (stmp.length() == 1) {
                hs = hs + "0" + stmp;
            } else {
                hs = hs + stmp;
            }
        }
        return hs.toLowerCase();
    }

    /**
     * 大数字转换字节流（字节数组）型数据
     *
     * @param n
     * @return
     */
    public static byte[] byteConvert32Bytes(BigInteger n) {
        byte tmpd[] = (byte[]) null;
        if (n == null) {
            return null;
        }

        if (n.toByteArray().length == 33) {
            tmpd = new byte[32];
            System.arraycopy(n.toByteArray(), 1, tmpd, 0, 32);
        } else if (n.toByteArray().length == 32) {
            tmpd = n.toByteArray();
        } else {
            tmpd = new byte[32];
            for (int i = 0; i < 32 - n.toByteArray().length; i++) {
                tmpd[i] = 0;
            }
            System.arraycopy(n.toByteArray(), 0, tmpd, 32 - n.toByteArray().length, n.toByteArray().length);
        }
        return tmpd;
    }

    /**
     * Convert hex string to byte[]
     *
     * @param hexString the hex string
     * @return byte[]
     */
    public static byte[] hexStringToBytes(String hexString) {
        if (hexString == null || hexString.equals("")) {
            return null;
        }

        hexString = hexString.toUpperCase();
        int length = hexString.length() / 2;
        char[] hexChars = hexString.toCharArray();
        byte[] d = new byte[length];
        for (int i = 0; i < length; i++) {
            int pos = i * 2;
            d[i] = (byte) (charToByte(hexChars[pos]) << 4 | charToByte(hexChars[pos + 1]));
        }
        return d;
    }

    /**
     * Convert char to byte
     *
     * @param c char
     * @return byte
     */
    public static byte charToByte(char c) {
        return (byte) "0123456789ABCDEF".indexOf(c);
    }

    /**
     * 十六进制串转化为byte数组
     *
     * @return the array of byte
     */
    public static byte[] hexToByte(String hex)
            throws IllegalArgumentException {
        if (hex.length() % 2 != 0) {
            throw new IllegalArgumentException();
        }
        char[] arr = hex.toCharArray();
        byte[] b = new byte[hex.length() / 2];
        for (int i = 0, j = 0, l = hex.length(); i < l; i++, j++) {
            String swap = "" + arr[i++] + arr[i];
            int byteint = Integer.parseInt(swap, 16) & 0xFF;
            b[j] = new Integer(byteint).byteValue();
        }
        return b;
    }
}
