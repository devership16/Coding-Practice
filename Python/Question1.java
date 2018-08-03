import java.io.*;
import java.util.*;

public class Question1 {
    public static  void main(String args[]) throws FileNotFoundException {
        File file = new File("/Users/waquarahmad/Desktop/Graduate Networks/Project_2/p2-p2-asha/fb_contest_question1/resources/tourist.txt");
        BufferedReader br = new BufferedReader(new FileReader(file));
        try{
        String line = br.readLine();
         int testCases = Integer.parseInt(line);
            //System.out.println(testCases);
            PrintWriter writer = new PrintWriter("Answer1.txt", "UTF-8");
         for(int i=0;i<testCases;i++)
         {  writer.print("Case"+" "+"#"+(i+1) +":");
             line = br.readLine();
             String[]split = line.split(" ");
             int N = Integer.parseInt(split[0]);
             int K  = Integer.parseInt(split[1]);
             long V = Long.parseLong(split[2]);
             System.out.println("V: "+V);
            Map<Integer,String> Names = new HashMap<>();
             for(int j=1;j<=N;j++) {
                String temp = br.readLine();
                 Names.put(j, temp);
             }
             //for(Map.Entry<Integer,String>entry :Names.entrySet())
                 //System.out.println(entry.getValue());

             PriorityQueue<Integer> pq1 = new PriorityQueue<>();
             PriorityQueue<Integer> pq2 = new PriorityQueue<>();
             for(Map.Entry<Integer,String>entry :Names.entrySet())
                 pq1.add(entry.getKey());
             List<Integer> result = new ArrayList<>();
             int flag = 1;
             long index=0;
             int gcdVal = gcd(N,K);
             int lcmVal = (N*K)/gcdVal;
             int repeatFactor = 2*(lcmVal/K);
             long totalCount = V%repeatFactor;
             if(totalCount==0)
                 totalCount = repeatFactor;
             //System.out.println("totalcount: "+totalCount)
             while(index<totalCount)
             {
                 int count = 0;
                 result = new ArrayList<>();
                 if(flag==1)
                 {
                     while(pq1.size()>0 && count<K)
                     {
                         int currNum = pq1.poll();
                         result.add(currNum);
                         count++;
                         pq2.offer(currNum);
                     }

                     if(pq1.size()==0)
                         flag = 2;

                     if(flag==2 && count<K)
                     {
                         while(count<K)
                         { int currNum = pq2.poll();
                         result.add(currNum);
                         count++;
                         pq1.offer(currNum);
                         }
                     }
                 }

                 else if(flag==2)
                 {
                     while(pq2.size()>0 && count<K)
                     {
                         int currNum = pq2.poll();
                         result.add(currNum);
                         count++;
                         pq1.offer(currNum);
                     }

                     if(pq2.size()==0)
                         flag=1;

                     if(flag==1 && count<K)
                     {
                         while(count<K)
                         {
                             int currNum = pq1.poll();
                             result.add(currNum);
                             count++;
                             pq2.offer(currNum);
                         }
                     }
                 }
                 index++;
             }
             Collections.sort(result);

             for(int name:result)
             { System.out.println(Names.get(name));
             writer.print(" "+Names.get(name));
             }
             writer.println("");
         }

            writer.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }

    }

    public static int gcd(int a,int b)
    {
        if(a==b)
            return a;
        else if(a>b)
            return gcd(a-b,b);
        else
            return gcd(a,b-a);
    }
}
