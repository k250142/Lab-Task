#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 200
#define MAXC 200

void trim(char*s){size_t n=strlen(s);if(n&&s[n-1]=='\n')s[n-1]=0;}

int words(const char*s){
    int c=0,in=0;
    while(*s){
        if(!isspace(*s)&&!in){in=1;c++;}
        else if(isspace(*s)) in=0;
        s++;
    }
    return c;
}

int ci_cmp(const char*a,const char*b){
    while(*a&&*b){
        char x=tolower(*a),y=tolower(*b);
        if(x!=y)return x>y?1:-1;
        a++;b++;
    }
    char x=tolower(*a),y=tolower(*b);
    return x>y?1:(x<y?-1:0);
}

int has(const char*t,const char*p){
    size_t lt=strlen(t),lp=strlen(p);
    for(size_t i=0;i+lp<=lt;i++){
        size_t j=0;
        while(j<lp && tolower(t[i+j])==tolower(p[j])) j++;
        if(j==lp)return 1;
    }
    return 0;
}

int cmp_q(const void*a,const void*b){
    return ci_cmp((const char*)a,(const char*)b);
}

int load(char a[][MAXC]){
    FILE*f=fopen("affirm.txt","r");
    if(!f) return 0;
    char b[MAXC];int i=0;
    while(i<MAX && fgets(b,sizeof(b),f)){
        trim(b);
        if(b[0]) strcpy(a[i++],b);
    }
    fclose(f);
    return i;
}

void save(char a[][MAXC],int n){
    FILE*f=fopen("affirm.txt","w");
    for(int i=0;i<n;i++) fprintf(f,"%s\n",a[i]);
    fclose(f);
}

int main(){
    char a[MAX][MAXC],x[MAXC];
    int n=load(a);

    while(1){
        printf("\n1 Add\n2 Delete\n3 Update\n4 Search\n5 Show\n-1 Exit\nChoice: ");
        fgets(x,sizeof(x),stdin);trim(x);
        if(!strcmp(x,"-1")) break;
        int c=atoi(x);

        if(c==1){
            printf("Enter: ");
            fgets(x,sizeof(x),stdin);trim(x);
            if(words(x)>7){printf("Max 7 words\n");continue;}
            strcpy(a[n++],x);
            printf("Added\n");
        }

        else if(c==2){
            printf("Title: ");
            fgets(x,sizeof(x),stdin);trim(x);
            int f=-1;
            for(int i=0;i<n;i++) if(!strcmp(a[i],x)){f=i;break;}
            if(f<0)printf("Not found\n");
            else{
                for(int i=f;i<n-1;i++) strcpy(a[i],a[i+1]);
                n--;
                printf("Deleted\n");
            }
        }

        else if(c==3){
            printf("Title: ");
            fgets(x,sizeof(x),stdin);trim(x);
            int f=-1;
            for(int i=0;i<n;i++) if(!strcmp(a[i],x)){f=i;break;}
            if(f<0)printf("Not found\n");
            else{
                printf("New: ");
                fgets(x,sizeof(x),stdin);trim(x);
                if(words(x)>7){printf("Max 7 words\n");continue;}
                strcpy(a[f],x);
                printf("Updated\n");
            }
        }

        else if(c==4){
            printf("Search: ");
            fgets(x,sizeof(x),stdin);trim(x);
            int ok=0;
            for(int i=0;i<n;i++) if(has(a[i],x)){printf("%d %s\n",i+1,a[i]);ok=1;}
            if(!ok)printf("No match\n");
        }

        else if(c==5){
            qsort(a,n,sizeof(a[0]),cmp_q);
            for(int i=0;i<n;i++) printf("%d %s\n",i+1,a[i]);
        }
    }

    qsort(a,n,sizeof(a[0]),cmp_q);
    save(a,n);
    printf("Saved\n");
    return 0;
}
