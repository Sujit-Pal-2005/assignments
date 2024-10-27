#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
//initialize the point
typedef struct point{
double x;
double y;
int cluster_id;
}point;

//distance calculation
double distance(point a,point b){
  return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
//function for assigning id
int assign_id(point points[],point cluster_points[],int n ,int k){
  int flag=0;
  for(int i=0;i<n;i++){
    int temp=points[i].cluster_id;
    double min_dist=distance(points[i],cluster_points[0]);
    points[i].cluster_id=0;
    for(int j=1;j<k;j++){
      double dist=distance(points[i],cluster_points[j]);
      if(dist<min_dist){
        min_dist=dist;
        points[i].cluster_id=j;
      }
    }
    if(temp!=points[i].cluster_id)flag++;
 }
 return flag;
}
//function for making new cluster
void new_cluster(point points[],point cluster_points[],int n ,int k){
  point new_cluster[k];
  int cluster_size[k];
  //initialize all the points with zero
  for(int i=0;i<k;i++){
    new_cluster[i].x=0;
    new_cluster[i].y=0;
    cluster_size[i]=0;
  }
  //finding average
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
  //assign new value to the previous cluster id
  for(int i=0;i<k;i++){
    cluster_points[i].x=new_cluster[i].x;
    cluster_points[i].y=new_cluster[i].y;
  }
}
//function for calculation
void cluster_calculation(point points[],point cluster_points[],int n ,int k){
  //call for assign id
  int flag=assign_id(points, cluster_points, n , k);
  //call for new cluster
  new_cluster(points, cluster_points, n , k);
  //checking
  if(flag){
    cluster_calculation(points,cluster_points,n,k);
  }
  
}

int main(){
  srand(time(NULL));
  //taking input
  int n,low,high,k;
  printf("Enter no of points:");
  scanf("%d",&n);
  printf("Enter low and high range of points :");
  scanf("%d %d",&low,&high);
  point points[n];
  printf("Enter no of cluster center :");
  scanf("%d",&k);
  //generate points in file
  double num;
  FILE *f=fopen("input.txt","w");
  for(int i=0;i<n;i++){
        num=(rand()/(double)RAND_MAX*(high-low))+low;
        points[i].x=num;
        fprintf(f,"%.2lf ",num);
        num=(rand()/(double)RAND_MAX*(high-low))+low;
        fprintf(f,"%.2lf \n",num);
        points[i].y=num;
        points[i].cluster_id=-1;
    }
  fclose(f);
  //Read from file
  // FILE *f1 =fopen("input.txt","r");
  // for(int i=0;i<100;i++){
  //   fscanf(f1,"%lf %lf",&points[i].x,&points[i].y);
  //   points[i].cluster_id =-1;
  // }
  // fclose(f1);
  //generate random cluster point
  point cluster_points[k];
  for(int i=0;i<k;i++){
    num=(rand()/(double)RAND_MAX*(high-low))+low;
    cluster_points[i].x=num;
    num=(rand()/(double)RAND_MAX*(high-low))+low;
    cluster_points[i].y=num;
  }
  //main work
  cluster_calculation(points,cluster_points,n,k);
  //write the answer in  file
  FILE *f2=fopen("output.txt","w");
    fprintf(f2,"%d %d \n",n,k);
    for(int i=0;i<n;i++){
      fprintf(f2,"%0.2lf %.2lf %d \n",points[i].x,points[i].y,points[i].cluster_id) ;
    }
    fclose(f2);
  return 0;

}
