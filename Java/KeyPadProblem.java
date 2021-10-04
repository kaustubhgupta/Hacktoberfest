public class KeyPadProblem {
    public String getKeysWithDigits(int num) {
        String result = "";
        switch (num) {
        case 0:
            result = "+";
            break;
        case 1:
            result = "";
            break;
        case 2:
            result = "abc";
            break;
        case 3:
            result = "def";
            break;
        case 4:
            result = "ghi";
            break;
        case 5:
            result = "jkl";
            break;
        case 6:
            result = "mno";
            break;
        case 7:
            result = "pqrs";
            break;
        case 8:
            result = "tuv";
            break;
        case 9:
            result = "wxyz";
            break;
        }
        return result;
    }

    public String[] getNumPad(int num) {
        if (num == 0) {
            String[] output = new String[1];
            output[0] = "";
            return output;
        }
        int lastDigit = num % 10;
        int remainingDigits = num / 10;
        String[] remainingDigitArray = getNumPad(remainingDigits);
        String getKeysforLastDigit = getKeysWithDigits(lastDigit);
        String output[] = new String[getKeysforLastDigit.length() * remainingDigitArray.length];
        int k = 0;
        for (int i = 0; i < remainingDigitArray.length; i++) {
            for (int j = 0; j < getKeysforLastDigit.length(); j++) {
                output[k] = remainingDigitArray[i] + getKeysforLastDigit.charAt(j);
                k++;
            }
        }
        return output;
    }

    public static void main(String[] args) {
        KeyPadProblem k = new KeyPadProblem();
        String[] output = k.getNumPad(23);
        for (int i = 0; i < output.length; i++) {
            System.out.println(output[i]);
        }
    }
}