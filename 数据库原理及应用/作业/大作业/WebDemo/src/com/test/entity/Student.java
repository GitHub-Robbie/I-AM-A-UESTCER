package com.test.entity;
public class Student {
    private String SID;
//    private String studentName;
    private String CID;
    private String Score;
    private String Note;

    public Student() { }

//    public Student(String studentID, String studentName, String courseID, String courseName, String courseGrade) {
    public Student(String SID, String CID, String Score, String Note) {
        this.SID=SID;
//        this.studentName=studentName;
        this.CID=CID;
        this.Score=Score;
        this.Note=Note;
    }

    public void setSID(String SID) { this.SID=SID; }
//    public void setStudentName(String studentName) { this.studentName=studentName; }
    public void setCID(String CID) { this.CID=CID; }
    public void setScore(String Score) { this.Score=Score; }
    public void setNote(String Note) { this.Note=Note; }

    public String getSID() { return this.SID; }
//    public String getStudentName() { return this.studentName; }
    public String getCID() { return this.CID; }
    public String getScore() { return this.Score; }
    public String getNote() { return this.Note; }

    public String toString() {
        return "People{" +
                "SID=" + SID +
                ", CID='" + CID + '\'' +
                ", Score=" + Score + ", Note='" + Note +
                '}';
    }
}