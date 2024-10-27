#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>


typedef struct point{
double x;
double y;
int cluster_id;
}point;

//distance calculation
double distance(point a,point b){
  distance=sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
void assign_id(point points[],point cluster_points[],int n ,int k){
 for(int i=0;i<n;i++){
    double min_dist=distance(points[i],cluster_points[0]);
        points[i].cluster_id=0;
    for(int j=1;j<k;j++){
     double dist=distance(points[i],cluster_points[j]);
     if(dist<min_dist){
      min_dist=dist;
      points[i].cluster_id=j;
     }
    }
 }
}
void new_cluster(point points[],point cluster_points[],int n ,int k){
     point new_cluster[k];
     int cluster_size[k]
     for(int i=0;i<k;i++){
        new_cluster[i].x=0;
        new_cluster[i].y=0;
        cluster_size[i]=0;
     }
     for(int i=0;i<n;i++){
     new_cluster[points[i].cluster_id].x+=points[i].x;
      new_cluster[points[i].cluster_id].y+=points[i].y;
       cluster_size[points[i].cluster_id]++;
     }
     for(int i=0;i<k;i++){
       if(cluster_size[i]>0){
        new_cluster[i].x/=cluster_size[i];
         new_cluster[i].y/=cluster_size[i];
        
       }
     }
     for(int i=0;i<k;i++){
       cluster_points[i].x=new_cluster[i].x;
       cluster_points[i].y=new_cluster[i].y;
     }
}
int check(point old_points[],point new_points[],int k){
       for(int i=0;i<k;i++){
         if(old_points[i].x!=new_points[i].x||old_points[i].y!=new_points[i].y){
             return 1;
         }
       }
       return 0;
}
void cluster_calculation(point points[],point cluster_points[],int n ,int k){
   point old_cluster[k];
   for(int i=0;i<k;i++){
        old_cluster[i].x=cluster_points[i].x;
        old_cluster[i].y=cluster_points[i].y;
   }
   assign_id(points, cluster_points, n , k);
   new_cluster(points, cluster_points, n , k);
   if(check(old_cluster,cluster_points,k)){
    cluster_calculation(points,cluster_points,n,k);
   }
   for(int i=0;i<k;i++){
        printf("%lf %lf\n",cluster_points[i].x,cluster_points[i].y);
        
   }
   
   

}

int main(){
point points[100];
srand(time(NULL));
int k=5;
FILE *f =fopen("input.txt","r");
for(int i=0;i<100;i++){
 fscanf(f,"%lf %lf",&points[i].x,&points[i].y);
 points[i].cluster_id =-1;
}
//generate 5 random cluster point
 point cluster_points[k];
 double num;
for(int i=0;i<k;i++){
 num=rand()/(double)RAND_MAX*10;
 cluster_points[i].x=num;
 num=rand()/(double)RAND_MAX*10;
 cluster_points[i].y=num;
}
cluster_calculation(points,cluster_points,100,k);

return 0;

}
