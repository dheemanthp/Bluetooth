

import java.io.*;
import java.util.*;

/*
 * To execute Java, please define "static void main" on a class
 * named Solution.
 *
 * If you need more classes, simply define them inline.
 */

/*

  |-----------------|
  |  1  |  2  |  3  |
  |     | ABC | DEF |
  |-----|-----|-----|
  |  4  |  5  |  6  |
  | GHI | JKL | MNO |
  |-----|-----|-----|
  |  7  |  8  |  9  |
  |PQRS | TUV | WXYZ|
  |-----|-----|-----|
  |     |  0  |     |
  |     | " " |     |
  |-----------------|


  input -> "44.33.555.555.666.0.9.666.777.555.3"
  return -> "HELLO WORLD"
*/


class Solution {
  
  String[]  letters = {
    " ",
    "",
    "ABC",
    "DEF",
    "GHI",
    "JKL",
    "MNO",
    "PQRS",
    "TUV",
    "WXYZ",
    "",
    "",
  };
  
  
  
  
  
  // let digits = "44.33.555.555.666.0.9.666.777.555.3"
  public String mapper (String digits) {
    StringBuilder output  = new StringBuilder();
    //base case
    if(digits == null || digits.length() == 0) return null;
    //create mapper for the input
    String[] mapping  = digits.split("\\.");
    System.out.println(" the digits is " + digits);
    System.out.println(" the mapping is " + Arrays.toString(mapping));
    for(int i = 0 ; i < mapping.length; i++ ) {
      
      
      // mapping[0] = "44" 
      int firstnum = Character.getNumericValue(mapping[i].charAt(0));
      System.out.println(" the firstnum is " + firstnum);
      int len = mapping[i].length() - 1;
      output.append(letters[firstnum].charAt(len));
    }
    return output.toString();
  }
  
  
  
  public static void main(String[] args) {
    
    
    Solution s = new Solution();
    String input = "44.33.555.555.666.0.9.666.777.555.3";
    System.out.println("The output is " + s.mapper(input));
  }
  
  
}

