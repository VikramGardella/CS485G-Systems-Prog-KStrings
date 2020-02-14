//Author: Dr. Moore, Editted by Vikram Dudee

#include "kstring.h"
#include <stdlib.h>
#include <string.h>

//using namespace std;


int sizetToInt(size_t t){
	int res = 0;
	size_t temp = t;
	while(temp>0){
		temp--;
		res++;
	}
	return res;
}

size_t intToSizet(int in){
	size_t r = 0;
	int i = in;
	if(i>0){
		while(i>0){
			i--;
			r++;
		}
	}
	return r;
}

char kstrget(kstring str, size_t pos){
	if(pos>=str.length)
		abort();
	return str.data[pos];
}

void kstrput(kstring str, size_t pos, char ch){
	if(pos>=str.length){
//		puts("INVALID PARAMETER.");
		abort();
	}
	else{
		str.data[pos] = ch;		

 //same tactic as kstrget to find where to insert, will need to resize though
/*When resizing, the amount to resize to should be tweaked depending on the
usage of the kstring. The reason being, if you resize it too much for a small insertion,
you will take up way too much memory after many insertions.but if you resize too
big in the first place and keep checking to see if you need to call extend in this function,
you might actually save a lot of time when it is being run since you cut down on the amount
of times the whole kstring needs to be resized. To keep it simple, I will only extend to a
larger size of 1 because checking if a call to the extend function is necessary might
actually be slower and worse than taking up too much memory.*/



	}
}

size_t kstrlen(kstring str){
/*	int l = 0;
	while(str)*/
	return str.length;
}

kstring kstralloc(size_t nbytes){
	char * data = (char *) calloc(nbytes, sizeof(char));
	
	for(size_t i = 0; i < nbytes; ++i){
		data[i] = '\0';
	}
	kstring result = {data, nbytes};
	return result;
}

kstring kstrfrom(const char *cstr){
	kstring result = kstralloc(strlen(cstr)+1);
	for(int i=0; i < strlen(cstr); i++){
		result.data[i] = cstr[i];
	}
	result.data[strlen(cstr)+1] = '\0';
	//kstrfree(result);
	return result;
}

void kstrfree(kstring str){
	//free buffer somehow
	//if(str.length == 0)
	//	abort();
	//else
		free(str.data);
}

void kstrextend(kstring *strp, size_t nbytes){
	if(nbytes>strp->length){
//		cout << "INVALID PARAMETERS." << endl;
	//	abort();
//	}
//	else{
		kstring big = kstralloc(nbytes); //has allocated space for the larger new kstring
//		char *curr = strp -> data; //Accessible member variavle???
		size_t oldsz = (*strp).length; //Accessible as well???
		for(int i=0; i<nbytes; i++){//now will put values into their corresponding spot in new array
			if(i<oldsz)
				big.data[i]= strp->data[i];	//kstrput(big, i, curr);
			else{
				big.data[i] = '\0';	//kstrput(big, i, '\0');//all new empty spaces get a null character
			}//end else
		}//end for
		//Since this is a void function, to put the new and improved kstring to use,
		//I will set the pointer to the old one to the new one.
		*strp = big;
		//kstrfree(*strp);
	}//end if
}//end function

void kstrcat(kstring *destp, kstring src){
	int oldl = sizetToInt((*destp).length);
	kstrextend(destp ,oldl + src.length);
	for(int i=oldl; i<oldl+src.length; i++){
		(*destp).data[i] = src.data[i-oldl];
	}

}
