package kakao_blind_recruitment.다트게임;

class Solution {

    public static void main(String[] args) {
        Solution sol = new Solution();
        int answer = sol.solution("1D2S3T*");

    }

    public int solution(String dartResult) {
        int answer = 0;

        int[] numbers = separate(dartResult);

        /*for (int i = 0; i < 3; i++) {
            System.out.println(numbers[i]);
        }*/

        for (int i = 0; i < 3; i++) {
            answer += numbers[i];
        }
        return answer;
    }

    private int[] separate(String dartResult) {
        StringBuilder sb = new StringBuilder(dartResult);
        int[] numbers = new int[3];


        for (int i = 0; i < 3; i++) {
            //첫 숫자가 한자리의 숫자인지 두 자리의 숫자인지 구분해야한다.
            boolean isOneInteger = true;

            if (sb.charAt(1) == '0') {
                isOneInteger = false;
            }

            if (isOneInteger) {
                numbers[i] = sb.charAt(0) - '0';
                sb.delete(0, 1);

                char square = sb.charAt(0);
                if (square == 'D') {
                    numbers[i] = numbers[i] * numbers[i];
                } else if (square == 'T') {
                    numbers[i] = numbers[i] * numbers[i] * numbers[i];
                }

                sb.delete(0, 1);

                if (sb.length() != 0) {

                    char option = sb.charAt(0);
                    boolean isOption = false;
                    if (option == '*') {
                        isOption = true;
                        if (i == 0) {
                            numbers[i] = numbers[i] * 2;
                        } else {
                            numbers[i - 1] = numbers[i - 1] * 2;
                            numbers[i] = numbers[i] * 2;
                        }
                    } else if (option == '#') {
                        isOption = true;
                        if (i == 0) {
                            numbers[i] = numbers[i] * -1;
                        } else {
                            numbers[i] = numbers[i] * -1;
                        }
                    }

                    if (isOption) {
                        sb.delete(0, 1);
                    }
                }

            } else {
                numbers[i] = 10;
                sb.delete(0, 2);

                char square = sb.charAt(0);
                if (square == 'D') {
                    numbers[i] = numbers[i] * numbers[i];
                } else if (square == 'T') {
                    numbers[i] = numbers[i] * numbers[i] * numbers[i];
                }

                sb.delete(0, 1);

                if (sb.length() != 0) {

                    char option = sb.charAt(0);
                    boolean isOption = false;
                    if (option == '*') {
                        isOption = true;
                        if (i == 0) {
                            numbers[i] = numbers[i] * 2;
                        } else {
                            numbers[i - 1] = numbers[i - 1] * 2;
                            numbers[i] = numbers[i] * 2;
                        }
                    } else if (option == '#') {
                        isOption = true;
                        if (i == 0) {
                            numbers[i] = numbers[i] * -1;
                        } else {
                            numbers[i] = numbers[i] * -1;
                        }
                    }

                    if (isOption) {
                        sb.delete(0, 1);
                    }
                }
            }

        }


        return numbers;
    }


}
