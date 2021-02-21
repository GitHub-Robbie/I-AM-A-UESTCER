package com.yhn.pojo;

public class People {
    private String sid;
    private String cid;
    private String score;
    private String note;

    @Override
    public String toString() {
        return "People{" +
                "sid=" + sid + ", cid=" + cid + ", score=" + score + ", note=" + note + '}';
    }

    public String getsid() { return sid; }
    public String getcid() { return cid; }
    public String getscore() { return score; }
    public String getnote() { return note; }

    public void setsid(String sid) { this.sid = sid; }
    public void setcid(String cid) { this.cid = cid; }
    public void setscore(String score) { this.score = score; }
    public void setnote(String note) { this.note = note; }

}
