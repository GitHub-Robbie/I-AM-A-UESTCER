package com;

public class Fun {
    //字符串转化为长整数数组
    public static long[] toLongarray(String str) {

        long[] data=new long[4];
        str=str.replaceAll(" ", "");
        if (str == null) {
            return null;
        }
        if (str.length() == 0) {
            return new long[0];
        }

        for (int i=0,j = 0; j < data.length; j++) {
            String c = str.substring(i,i+8);
            data[j]=Long.parseLong(c, 16);
            i=i+8;
        }

        return data;
    }
}
