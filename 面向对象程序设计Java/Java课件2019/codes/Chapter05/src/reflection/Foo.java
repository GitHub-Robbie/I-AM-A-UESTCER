package reflection;

class Foo { 
    private String msg; 

    public Foo(String msg) { 
        this.msg = msg; 
    } 

    private void setMsg(String msg) {
        this.msg = msg; 
        System.out.println("重新设置信息"); 
    } 

    private String getMsg() { 
        return msg; 
    } 

    private void outInfo() {
        System.out.println("这是测试Java反射的测试类"); 
    } 
}
