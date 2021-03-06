//  #include <string> 
//  using std::string;

//  string s1;         //默认初始化，s1是一个空字符串
//  string s2 = s1;    //s2是s1的副本 拷贝初始化
//  string s2(s1);     //s2是s1的副本 直接初始化
//  string s3 = "hiya";//s3是该字符串字面值的副本 拷贝初始化
//  string s3("value");//s3是字面值"value"的副本，除了字面值最后的那个空字符外
//  string s4(10, 'c');//s4的内容是cccccccccc

//当初始值只有一个时，使用直接初始化或者拷贝初始化都行。
//但如果像上面的s4那样初始化要用到的值有多个，一般来说只能用直接初始化的方式。

//一个类除了要规定初始化其对象的方式外，还要定义对象上所能执行的操作。
//其中，类既能定义通过函数名调用的各种操作，就像Sales_item类的isbn函数那样，
//也能定义<<, +等各种运算符在该类对象上的新含义。