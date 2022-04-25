#include <stdio.h>
#include <stdlib.h>

/* 
Na rwtaw posous anthrwpous paratirei
me synartiseis:
na gemisw pinakes me pointers, gia kathe anthrwpo na zitaw thn ilikia tou(int) ta kila tou(double)
display --> 1. 19xronwn, 35.5kila me pointers
mo ilikiwn olwn twn anthrwpwn me pointers
mo kilwn mono gia tous anthrwpous katw apo 30 xronwn me pointers
na metrisw posoi einai panw apo 20 xronwn kai posoi einai katw apo 20 me pointers
na taksinomisw tous 2 pinakes se fthinousa ws pros tin ilikia me pointers
display 
na zitaw mia ilikia kai na ektipwnw ta kila tou anthrwpou an yparxei alliws den vrethike me pointers
na metrisw posoi anthrwpoi exoun ilikia panw apo 18 xronwn kai killa katw apo 70 XWRIS pointers
*/
void gemisma(int *ilikia_list,double *kila_list,int an);
void display(int *ilikia_list,double *kila_list,int an);
void mo_ilikiwn(int *ilikia_list,int an);
void mo_kilwn_gia_katw_apo_30(int *ilikia_list, double *kila_list, int an);
void over_under(int *ilikia_list,int an,int *over,int *under);
void sorting_desc_ilikia(int *ilikia_list,int an,double *kila_list);
void searching(int *ilikia_list, double *kila_list, int an);
void counter(double kila_list[],int ilikia_list[],int an);

int main(){
	
	int over=0,under=0;
	int an;
	printf("Posous anthrwpous paratiris? ");
	scanf("%i",&an);
	int ilikia_list[an];
	double kila_list[an];
	
	gemisma(&ilikia_list[0],&kila_list[0],an);
	display(&ilikia_list[0],&kila_list[0],an);
	mo_ilikiwn(&ilikia_list[0],an);
	mo_kilwn_gia_katw_apo_30(&ilikia_list[0],&kila_list[0],an);
	
	over_under(&ilikia_list,an,&over,&under);
	printf("Over: %i Under: %i\n",over,under);
	
	sorting_desc_ilikia(&ilikia_list[0],an,&kila_list[0]);
	display(&ilikia_list[0],&kila_list[0],an);
	
	searching(&ilikia_list[0],&kila_list[0],an);
	counter(kila_list,ilikia_list,an);

	return 0;
}

//gemisma me pointers
void gemisma(int *ilikia_list,double *kila_list,int an){
	int i;
	int ilikia;
	double kila;
	for (i=0; i<an; i++){
		printf("Dwse tin ilikia tou %iou anthrwpou: ",i+1);
		scanf("%i",&ilikia);
		printf("Dwse ta kila tou %iou anthrwpou: ",i+1);
		scanf("%lf",&kila);
		*(ilikia_list+i)=ilikia;
		*(kila_list+i)=kila;
	}
}

//display me pointers
void display(int *ilikia_list,double *kila_list,int an){
	int i;
	printf("\n");
	for (i=0; i<an; i++){
		printf("%i. %ixronwn, %.2fkila\n",i+1,*(ilikia_list+i),*(kila_list+i));
	}
}

//mo ilikiwn olwn twn anthrwpwn me pointers
void mo_ilikiwn(int *ilikia_list,int an){
	int i;
	int sum=0;
	double mo;
	for (i=0; i<an; i++){
		sum=sum+(*(ilikia_list+i));
	}
	if (an==0){
		mo=0;
	}
	else{
		mo=(double)sum/an;
	}
	printf("O mo twn ilikiwn olwn twn anthrwpwn einai ta %.2f xronia\n",mo);
}
//mo kilwn mono gia tous anthrwpous katw apo 30 xronwn me pointers
void mo_kilwn_gia_katw_apo_30(int *ilikia_list, double *kila_list, int an){
	int i;
	double sum=0;
	double mo;
	int count=0;
	for (i=0; i<an; i++){
		if ((*(ilikia_list+i))<30){
			sum=sum+*(kila_list+i);
			count++;
		}
	}
	if (count==0){
		mo=0;
	}
	else{
		mo=sum/count;
	}
	printf("O mo twn kilwn gia autous katw apo 30 einai %.2f\n",mo);
}

//na metrisw posoi einai panw apo 20 xronwn kai posoi einai katw apo 20 me pointers
void over_under(int *ilikia_list,int an,int *over,int *under){
	int i;
	for (i=0; i<an; i++){ 
		if (*(ilikia_list+i)>20){ //panw apo 20
			*over=*over+1;
		}
		else{ //20 kai katw
			*under=*under+1;
		}
	}
}

//na taksinomisw tous 2 pinakes se fthinousa ws pros tin ilikia me pointers
void sorting_desc_ilikia(int *ilikia_list,int an,double *kila_list){
	int i,j;
	int temp;
	double temp1;
	for (i=0; i<an-1; i++){
		for (j=0; j<an-i-1; j++){  
			if (*(ilikia_list+j)<*(ilikia_list+(j+1))){
			//swap ilikiwn
			temp=*(ilikia_list+j);
			*(ilikia_list+j)=*(ilikia_list+(j+1));
			*(ilikia_list+(j+1))=temp;
			//swap kilwn
			temp1=*(kila_list+j);
			*(kila_list+j)=*(kila_list+(j+1));
			*(kila_list+(j+1))=temp1;
			}
		}
	}
}

//searching ilikias
void searching(int *ilikia_list, double *kila_list, int an){
	int pos=-1;
	int i;
	int ilikia;
	printf("\nDwse mia ilikia: ");
	scanf("%i",&ilikia);
	
	for (i=0; i<an; i++){
		if (*(ilikia_list+i)==ilikia){
			pos=i;
			printf("Vrethike, tin exei o %ios anthrwpos pou einai %.2f kila\n",pos+1,*(kila_list+pos));
		}
	}
	if (pos==-1){
		printf("H ilikia den vrethike!!!\n");
	}
} 

//na metrisw posoi anthrwpoi exoun ilikia panw apo 18 xronwn kai killa katw apo 70 XWRIS pointers
void counter(double kila_list[],int ilikia_list[],int an){
	int i;
	int count=0;
	for (i=0; i<an; i++){
		if (ilikia_list[i]>18 && kila_list[i]<70){
			count++;
		}
	}
	if (count==0){
		printf("Den yparxoun anthrwpoi panw apo 18 xronwn kai katw apo 70 kila!!!\n");
	}
	else{
		printf("Oi anthrwpoi me ilikia panw apo 18 kai kila katw apo 70 einai %i",count);
	}
}
