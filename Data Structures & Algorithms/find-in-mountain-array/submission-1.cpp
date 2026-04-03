/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    const int NOT_FOUND = -1;
    unordered_map<int, int> mp = unordered_map<int, int>();
    int bl, br;

    int get_val(int k, MountainArray& mountainArr) {
        if (k < 0) {
            return -1;
        }
        if (!mp.count(k)) {
            mp[k] = mountainArr.get(k);
        }
        return mp[k];
    }

public:
    int search(int l, int r, int target, MountainArray& mountainArr) {
        if (l <= r) {
            int mid = l + (r - l) / 2;
            int val = get_val(mid, mountainArr);
            int prev_val = -1;
            if (bl < mid && mid < br) {
                prev_val = get_val(mid - 1, mountainArr);
            } else if (mid <= bl) {
                prev_val = INT_MIN;
            } else {
                prev_val = INT_MAX;
            }
            if (prev_val < val) {
                bl = max(bl, mid);
                if (val == target) {
                    return mid;
                }
                if (val < target) {
                    return search(mid + 1, r, target, mountainArr);
                } else {
                    int ans = search(l, mid - 1, target, mountainArr);
                    if (ans != NOT_FOUND) {
                        return ans;
                    }
                    return search(mid + 1, r, target, mountainArr);
                }
            } else {
                br = min(br, mid);
                if (val == target) {
                    int ans_left = search(l, mid - 1, target, mountainArr);
                    if (ans_left != NOT_FOUND) {
                        return ans_left;
                    }
                    return mid;
                } else {
                    if (val < target) {
                        return search(l, mid - 1, target, mountainArr);
                    } else {
                        int ans = search(l, mid - 1, target, mountainArr);
                        if (ans != NOT_FOUND) {
                            return ans;
                        }
                        return search(mid + 1, r, target, mountainArr);
                    }
                }
            }
        }
        return NOT_FOUND;
    }
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length(), l = 0, r = n - 1, ans = -1;
        bl = 0;
        br = n - 1;
        return max(ans, search(l, r, target, mountainArr));
    }
};