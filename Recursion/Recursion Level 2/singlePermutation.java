
// single permutaion -- subsequence wale tareeke se (without using any for loop)

public static int singlePermutation_subseq(int[] coins, int tar, boolean[] vis, String asf, int idx) {

        if (tar == 0 || idx >= coins.length) {
            if (tar == 0) {
                System.out.println(asf);
                return 1;
            }
            return 0;
        }

        int count = 0;

        if (tar - coins[idx] >= 0 && !vis[idx]){
            vis[idx] = true;
            count += singlePermutation_subseq(coins, tar - coins[idx], vis, asf + coins[idx] + " " , idx + 1);
            vis[idx] = false;
        }

        if ( !vis[idx]){
            vis[idx] = true;
            count += singlePermutation_subseq(coins, tar, vis,  asf , idx+1);
            vis[idx] = false;
        }
        return count;
    }