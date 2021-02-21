package cn.constantine3.encryption.utils.sm2;

import org.bouncycastle.math.ec.ECPoint;
import cn.constantine3.encryption.utils.Util;
import cn.constantine3.encryption.test.SecurityTest;

import java.math.BigInteger;

public class SM2KeyVO {
    BigInteger privateKey ;
    ECPoint publicKey ;

    // Java Bean, Although not all used, please keep
    public BigInteger getPrivateKey() {
        return privateKey;
    }

    public void setPrivateKey(BigInteger privateKey) {
        this.privateKey = privateKey;
    }

    public ECPoint getPublicKey() {
        return publicKey;
    }

    public void setPublicKey(ECPoint publicKey) {
        this.publicKey = publicKey;
    }

    public String getPubHexInSoft(){
        return Util.byteToHex(publicKey.getEncoded());
    }
    public String getPubHexInHard(){
        return SecurityTest.SM2PubHardKeyHead +Util.byteToHex(publicKey.getEncoded());
    }
    public String getPriHexInSoft(){
        return Util.byteToHex(privateKey.toByteArray());
    }
}
