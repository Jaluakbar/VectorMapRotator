#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#define M_PI 3.14159265358979323846264338327950288
using namespace std;

vector<vector<int>> eentjes_vinder(vector<vector<bool>> const & vec){
	//geeft de koordinaat van de true waarden, en maakt ze ook false(0)
	vector<vector<int>> de_eentjes = {};
	for(unsigned int i=0;i<vec.size();i++){
		for(unsigned int j=0;j<vec[i].size();j++){
			if(vec[i][j]==1){
				int a = i;
				int b = j;
				de_eentjes.push_back({a,b});
			}
		}
	}
	return de_eentjes;
}

vector<vector<bool>> rotate_matrix(vector<vector<bool>> const & mtx, int degree){
	//maakt een niewe vector met de nieuwe koordinaten
	degree = 360-degree; //clockwise
	int vec_mid_breed = mtx.size()/2;
	int vec_mid_lengte= mtx[1].size()/2;
	vector<vector<bool>> new_vec = mtx;
	vector<vector<int>> koordinaats = eentjes_vinder(mtx);
	float koordinaat_x =0;
	float koordinaat_y =0;
	float oud_x = 0;
	float oud_y = 0;
	
	for(unsigned int i =0;i<koordinaats.size();i++){ //nieuw vec leeg maken
		int point_a = koordinaats[i][0];
		int point_b = koordinaats[i][1];
		new_vec[point_a][point_b]=0;
	}
									
	for(unsigned int i=0;i<koordinaats.size();i++){ //nieuw koordinaten berekenen
		oud_x = koordinaats[i][0] - vec_mid_breed;
		oud_y = koordinaats[i][1] - vec_mid_lengte;
		
		koordinaat_x = round((oud_x * cos((degree*M_PI)/180))+ (oud_y * -sin((degree*M_PI)/180)));
		koordinaat_y = round((oud_x * sin((degree*M_PI)/180)) + (oud_y * cos((degree*M_PI)/180)));
		
		koordinaat_x +=vec_mid_breed;
		koordinaat_y +=vec_mid_lengte;
		
		//cout << new_koordinaats[i][0] << ','<< new_koordinaats[i][1] << endl;
		new_vec[koordinaat_x][koordinaat_y]=1;
	}
	return new_vec;
	
}

/*
int main(){
	printf("hello world\n");
	vector<vector<bool>> een = { {0,0,1,0,0,0,0,0,0,0},
								{0,0,1,0,0,0,0,0,0,0},
								{0,0,1,0,0,0,0,0,0,0},
								{0,0,1,0,0,0,0,0,0,0},
								{0,0,1,0,0,0,0,0,0,0},
								{0,0,1,0,0,0,0,0,0,0},
								{0,0,1,0,0,0,0,0,0,0},
								{0,0,1,0,0,0,0,0,0,0},
								{0,0,1,0,0,0,0,0,0,0},
								{0,0,1,0,0,0,0,0,0,0}};
	
	vector<vector<bool>> twee = rotate_matrix(een,45);
	
	vector<vector<int>> locatie = eentjes_vinder(een);
	
	for(unsigned int i=0;i<een.size();i++){
		for(unsigned int j=0;j<een[i].size();j++){
			cout << een[i][j] << ',';
		}
		cout << "\n";
	}
	
	cout << "\n";
	
	for(unsigned int i=0;i<twee.size();i++){
		for(unsigned int j=0;j<twee[i].size();j++){
			cout << twee[i][j] << ',';
		}
		cout << "\n";
	}
	
}*/
