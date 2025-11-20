#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10
#define MAXC 200

void trim(char *s){ size_t n=strlen(s); if(n && s[n-1]=='\n') s[n-1]=0; }

int words(const char *s){
    int c=0, in=0;
    while(*s){
        if(!isspace((unsigned char)*s) && !in){ in=1; c++; }
        else if(isspace((unsigned char)*s)) in=0;
        s++;
    }
    return c;
}

int load(char a[][MAXC]){
    FILE *f=fopen("playlist.txt","r");
    if(!f) return 0;
    char b[MAXC]; int i=0;
    while(i<MAX && fgets(b,sizeof(b),f)){
        trim(b);
        if(b[0]==0) continue;
        strcpy(a[i++], b);
    }
    fclose(f);
    return i;
}

void save(char a[][MAXC], int n){
    FILE *f=fopen("playlist.txt","w");
    for(int i=0;i<n;i++) fprintf(f,"%s\n", a[i]);
    fclose(f);
}

int ci_cmp_str(const char *p, const char *q){
    unsigned char a,b;
    while(*p && *q){
        a = (unsigned char) tolower((unsigned char)*p);
        b = (unsigned char) tolower((unsigned char)*q);
        if(a != b) return (a > b) ? 1 : -1;
        p++; q++;
    }
    a = (unsigned char) tolower((unsigned char)*p);
    b = (unsigned char) tolower((unsigned char)*q);
    return (a > b) ? 1 : (a < b) ? -1 : 0;
}

int ci_contains(const char *text, const char *pat){
    if(!*pat) return 1;
    size_t lt = strlen(text), lp = strlen(pat);
    for(size_t i=0;i+lp<=lt;i++){
        size_t j=0;
        for(; j<lp; j++){
            if(tolower((unsigned char)text[i+j]) != tolower((unsigned char)pat[j])) break;
        }
        if(j==lp) return 1;
    }
    return 0;
}

int cmp_for_qsort(const void *a, const void *b){
    const char *pa = (const char *)a;
    const char *pb = (const char *)b;
    return ci_cmp_str(pa, pb);
}

int main(){
    char s[MAX][MAXC];
    int n = load(s);
    char x[MAXC];
    printf("Playlist Manager\n");

    while(1){
        printf("\n1 Add\n2 Delete\n3 Update\n4 Search\n5 Show\n-1 Exit\nChoose: ");
        if(!fgets(x,sizeof(x),stdin)) break;
        trim(x);
        if(strcmp(x,"-1")==0) break;
        int c = atoi(x);

        if(c==1){
            if(n>=MAX){ printf("Full\n"); continue; }
            printf("Enter title: ");
            if(!fgets(x,sizeof(x),stdin)) break;
            trim(x);
            if(words(x)<5 || words(x)>7){ printf("5-7 words only\n"); continue; }
            strcpy(s[n++], x);
            printf("Added\n");
        }

        else if(c==2){
            printf("Enter title to delete: ");
            if(!fgets(x,sizeof(x),stdin)) break;
            trim(x);
            int f=-1;
            for(int i=0;i<n;i++) if(strcmp(s[i],x)==0) { f=i; break; }
            if(f==-1) printf("Not found\n");
            else{
                for(int i=f;i<n-1;i++) strcpy(s[i],s[i+1]);
                n--;
                printf("Deleted\n");
            }
        }

        else if(c==3){
            printf("Enter title to update: ");
            if(!fgets(x,sizeof(x),stdin)) break;
            trim(x);
            int f=-1;
            for(int i=0;i<n;i++) if(strcmp(s[i],x)==0) { f=i; break; }
            if(f==-1) printf("Not found\n");
            else{
                printf("Enter new title: ");
                if(!fgets(x,sizeof(x),stdin)) break;
                trim(x);
                if(words(x)<5 || words(x)>7){ printf("5-7 words only\n"); continue; }
                strcpy(s[f], x);
                printf("Updated\n");
            }
        }

        else if(c==4){
            printf("Search: ");
            if(!fgets(x,sizeof(x),stdin)) break;
            trim(x);
            int ok=0;
            for(int i=0;i<n;i++){
                if(ci_contains(s[i], x)){
                    printf("%d %s\n", i+1, s[i]);
                    ok=1;
                }
            }
            if(!ok) printf("No match\n");
        }

        else if(c==5){
            qsort(s, n, sizeof(s[0]), cmp_for_qsort);
            for(int i=0;i<n;i++) printf("%d %s\n", i+1, s[i]);
        }

        else printf("Wrong choice\n");
    }

    qsort(s, n, sizeof(s[0]), cmp_for_qsort);
    save(s,n);
    printf("Saved\n");
    return 0;
}


