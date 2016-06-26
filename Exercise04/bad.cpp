    // file bad.cc

    int test(int a, double c){
    	return a;
    }

    int test(int a, double b){
    	return a+b;
    }

    void f (double c)
    {
    	test(1, 2);
    }

