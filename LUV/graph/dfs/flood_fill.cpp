// https://leetcode.com/problems/flood-fill/

#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int initialColour, int finalColour, vector<vector<int>> &image){
    int n=image.size();
    int m=image[0].size();
    if(i>=n || j>=m) return;
    if(i<0 || j<0) return;
    if(image[i][j]!=finalColour) return;;

    image[i][j] = finalColour;

    dfs(i-1,j,initialColour,finalColour,image);
    dfs(i+1,j,initialColour,finalColour,image);
    dfs(i,j-1,initialColour,finalColour,image);
    dfs(i,j+1,initialColour,finalColour,image);


}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initialColor = image[sr][sc];
    dfs(sr,sc,initialColor,color,image);
}
int main(){

}