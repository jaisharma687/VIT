public class AESRound1Decryption {
    private static final int[][] InvSBox = {
        {0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB},
        {0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB},
        {0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E},
        {0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25},
        {0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92},
        {0x6C, 0x70, 0x48, 0x50, 0xFD, 0xEB, 0x5F, 0x90, 0x58, 0x27, 0xB8, 0x4F, 0x8D, 0x71, 0x64, 0xCB},
        {0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E},
        {0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25},
        {0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92},
        {0x6C, 0x70, 0x48, 0x50, 0xFD, 0xEB, 0x5F, 0x90, 0x58, 0x27, 0xB8, 0x4F, 0x8D, 0x71, 0x64, 0xCB},
        {0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E},
        {0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25},
        {0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92},
        {0x6C, 0x70, 0x48, 0x50, 0xFD, 0xEB, 0x5F, 0x90, 0x58, 0x27, 0xB8, 0x4F, 0x8D, 0x71, 0x64, 0xCB},
        {0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E},
        {0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25}
    };

    private static final int[][] InvMixColMat = {
        {0x0E, 0x0B, 0x0D, 0x09},
        {0x09, 0x0E, 0x0B, 0x0D},
        {0x0D, 0x09, 0x0E, 0x0B},
        {0x0B, 0x0D, 0x09, 0x0E}
    };

    private static int gmul(int a, int b) {
        int p = 0;
        for (int i = 0; i < 8; i++) {
            if ((b & 1) != 0)
                p ^= a;
            boolean hiBit = (a & 0x80) != 0;
            a <<= 1;
            if (hiBit)
                a ^= 0x1B;
            b >>= 1;
        }
        return p & 0xFF;
    }

    private static void AddRoundKey(int[][] state, int[][] key) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                state[i][j] ^= key[i][j];
    }

    private static void InvSubBytes(int[][] state) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                state[i][j] = InvSBox[state[i][j] >> 4][state[i][j] & 0x0F];
    }

    private static void InvShiftRows(int[][] state) {
        int temp;

        // Row 1 shift right by 1
        temp = state[1][3];
        for (int i = 3; i > 0; i--)
            state[1][i] = state[1][i - 1];
        state[1][0] = temp;

        // Row 2 shift right by 2
        swap(state[2], 0, 2);
        swap(state[2], 1, 3);

        // Row 3 shift right by 3 (left by 1)
        temp = state[3][0];
        for (int i = 0; i < 3; i++)
            state[3][i] = state[3][i + 1];
        state[3][3] = temp;
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private static void InvMixColumns(int[][] state) {
        int[][] temp = new int[4][4];

        for (int c = 0; c < 4; c++) {
            for (int r = 0; r < 4; r++) {
                temp[r][c] = gmul(InvMixColMat[r][0], state[0][c]) ^
                             gmul(InvMixColMat[r][1], state[1][c]) ^
                             gmul(InvMixColMat[r][2], state[2][c]) ^
                             gmul(InvMixColMat[r][3], state[3][c]);
            }
        }

        // Copy temp to state
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                state[i][j] = temp[i][j];
    }

    private static void PrintState(String msg, int[][] state) {
        System.out.println(msg + ":");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                System.out.printf("%02X ", state[i][j]);
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Given ciphertext and key matrices
        int[][] state = {
            {0xC0, 0xA9, 0xC9, 0x9D},
            {0xEE, 0x07, 0x92, 0xAC},
            {0xB4, 0x4F, 0x10, 0x2F},
            {0x26, 0x34, 0xF9, 0xC1}
        };

        int[][] key = {
            {0x01, 0x01, 0x01, 0x01},
            {0x02, 0x02, 0x02, 0x02},
            {0x03, 0x03, 0x03, 0x03},
            {0x04, 0x04, 0x04, 0x04}
        };

        // Perform AES Decryption steps
        InvMixColumns(state);
        PrintState("After InvMixColumns", state);

        InvShiftRows(state);
        PrintState("After InvShiftRows", state);

        InvSubBytes(state);
        PrintState("After InvSubBytes", state);

        AddRoundKey(state, key);
        PrintState("After AddRoundKey", state);

        System.out.println("State after Round 1 Decryption:");
        PrintState("total", state);
    }
}