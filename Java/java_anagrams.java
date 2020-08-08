import java.util.Scanner;

public class Solution {

    static boolean isAnagram(String a, String b) 
    {
        int[] a_alph;
        int[] b_alph;
         a_alph = new int[26];
         b_alph = new int[26];
         java.util.Arrays.fill(a_alph, 0);
         java.util.Arrays.fill(b_alph, 0);
         final int len = a.length();
         if(a.length() == b.length())
         {
             for (int i = 0; i < len; i++)
             {
                 if(a.charAt(i) >= 'A' && a.charAt(i) <= 'Z')
                 {
                     a_alph[a.charAt(i) - 'A'] += 1;
                 }
                 else if(a.charAt(i) >= 'a' && a.charAt(i) <= 'z')
                 {
                     a_alph[a.charAt(i) - 'a'] += 1;
                 }
                 if(b.charAt(i) >= 'A' && b.charAt(i) <= 'Z')
                 {
                     b_alph[b.charAt(i) - 'A'] += 1;
                 }
                 else if(b.charAt(i) >= 'a' && b.charAt(i) <= 'z')
                 {
                     b_alph[b.charAt(i) - 'a'] += 1;
                 } 
             }
         }
         else
         {
             for (int i = 0; i < a.length(); i++)
             {
                 if(a.charAt(i) >= 'A' && a.charAt(i) <= 'Z')
                 {
                     a_alph[a.charAt(i) - 'A'] += 1;
                 }
                 else if(a.charAt(i) >= 'a' && a.charAt(i) <= 'z')
                 {
                     a_alph[a.charAt(i) - 'a'] += 1;
                 }
             }
             for (int i = 0; i < b.length(); i++)
             {
                 if(b.charAt(i) >= 'A' && b.charAt(i) <= 'Z')
                 {
                     b_alph[b.charAt(i) - 'A'] += 1;
                 }
                 else if(b.charAt(i) >= 'a' && b.charAt(i) <= 'z')
                 {
                     b_alph[b.charAt(i) - 'a'] += 1;
                 } 
             }
         }
         //  System.out.println(java.util.Arrays.equals(a_alph, b_alph) ? "Anagrams" : "Not Anagrams");
         return java.util.Arrays.equals(a_alph, b_alph);
    }

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
