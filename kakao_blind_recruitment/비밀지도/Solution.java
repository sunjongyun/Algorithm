package kakao_blind_recruitment.비밀지도;

public class Solution {


    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = {};


        int[] result=getMap(n,arr1,arr2);
        answer=MakeAnswer(n,result);

        return answer;
    }



    private String[] MakeAnswer(int n,int[] result) {
        String[] answer=new String[n];

        for (int i = 0; i <n ; i++) {
            answer[i]=fromIntToString(n,result[i]);
        }

        return answer;
    }

    private String fromIntToString(int n, int result) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i <n ; i++) {
            if ( result%2 == 1){
                sb.append("#");
            }else {
                sb.append(" ");
            }

            result=result/2;
        }
        sb.reverse();

        return sb.toString();
    }


    private int[] getMap(int n, int[] arr1, int[] arr2) {
        int[] result=new int[n];

        for (int i=0; i<n; i++){
            result[i]=arr1[i] | arr2[i];
        }

        return result;
    }


}
