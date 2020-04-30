public class MyClass {
    public static void main(String args[]) {
      int x= 4;
      //ones compliment 
      int result = ~4;
      //2's compliment
      result  = -(result);

      //-X = ~x + 1   ;
      //-~X = X + 1;

      System.out.println(result);
      
      // the problem is to CLEAR 3 bits at position 3,4,5 for the given number y
      int y = 121;//number
      int b = 4;//4 bits
      int pos = 3;//3; // starting from position 3, which 3, 4, 5
      int mask = (1<< b)-1;
      System.out.println(" the mask is " + mask);
      
      result =  y & ~(mask << (pos));
      System.out.println(" CLEAR result is " + result);
      
      
      // the problem is to SET 3 bits at position 3,4,5 for the given number y
      int yy = 1;//57; // number  000111001
      int bb = 4;//3;  //3 bits
      int poss = 3;//3; // starting from position 3, which 3, 4, 5
      int maskk = (1<< bb)-1;
      System.out.println(" the mask is " + maskk);
      
      result =  yy | (maskk << poss);
      System.out.println(" SET result is " + result);
      
      //toggle the 3 bits at position 3,4,5, for a given number
      int yyy = 89; //0101 1001
      int bbb = 4;
      int maskkk = (1 << bbb) - 1;
      int posss = 3; //3,4,5,6;
      result = yyy ^ (mask <<poss); // expectation is 0010 0001 (33)
      System.out.println(" TOGGLE result is " + result);
      
      
      //right most set bit position
      //get the common prefix by doing n & n-1 
      // Xor the Common prefix with n , will give you the right most bit position which is set
      int numVal = 20; //rightmost bit set is at position 3
      //00010100 n &
      //00010011 n-1
      //00010000 result
      // result  =  n ^ result;
      //00010100 n ^
      //00010000 result
      //00000100 result
      result  = (numVal & numVal-1);//common prefix
      result = result ^ numVal;
      int count = 0;
      while (result!=0) {
          result = result >>1;
          count++;
      }
      System.out.println(" bit set is position " + count);

    }
}
