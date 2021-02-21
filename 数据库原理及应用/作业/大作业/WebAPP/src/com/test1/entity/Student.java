package com.test1.entity;


public class Student {
    private String sid;
    private String sname;
    private String sex;
    private String cid;
    private String cname;
    private String teacher;
    private String score;
    private String note;

    public Student() { }

    public String getsid(){ return sid; }
    public String getsname(){ return sname; }
    public String getsex(){ return sex; }
    public String getcid(){ return cid; }
    public String getcname(){ return cname; }
    public String getteacher(){ return teacher; }
    public String getscore(){ return score; }
    public String getnote(){ return note; }

    public void setsid(String sid) { this.sid = sid; }
    public void setsname(String sname) { this.sname = sname; }
    public void setsex(String sex) { this.sex = sex; }
    public void setcid(String cid) { this.cid = cid; }
    public void setcname(String cname) { this.cname = cname; }
    public void setteacher(String teacher) { this.teacher = teacher; }
    public void setscore(String score) { this.score = score; }
    public void setnote(String note) { this.note = note; }

    public Student(String sid, String sname, String sex, String cid, String cname, String teacher, String score, String note) {
        this.sid=sid;
        this.sname=sname;
        this.sex=sex;
        this.cid=cid;
        this.cname=cname;
        this.teacher=teacher;
        this.score=score;
        this.note=note;
    }
    @Override
    public String toString() {
        return "Student{" +
                "sid=" + sid + ", sname=" + sname + ", sex=" + sex + ", cid=" + cid +
                ", cname=" + cname + ", teacher=" + teacher + ", score=" + score + ", note=" + note +
                '}';
    }
}


