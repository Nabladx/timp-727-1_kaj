#include <stdio.h>

#include <stdlib.h>

/* ñòðóêòóðà äëÿ õðàíåíèÿ óçëà äåðåâà. Íåîáõîäèìî õðàíèòü

ññûëêè íà ïîòîìêîâ, ïðåäêà è íåêîòîðîå çíà÷åíèå (öåëîå ÷èñ

ëî) */



struct node_l

{

    struct node *value; // çíà÷åíèå, êîòîðîå õðàíèò óçåë

    struct node_l *next; // ññûëêà íà ñëåäóþùèé ýëåìåíò ñïèñêà

};



struct list

{

struct node_l *head; // íà÷àëî ñïèñêà

struct node_l *tail; // êîíåö ñïèñêà

};



// èíèöèàëèçàöèÿ ïóñòîãî ñïèñêà

void init_l(struct list* l)

{

    l->head = NULL;

    l->tail = NULL;

}

//óäàëèòü âñå ýëåìåíòû èç ñïèñêà

void clear_l(struct list* l)

{

    struct node_l *buf;



    while(l->head != NULL)

    {

        buf = l->head;

        l->head = l->head->next;

        free(buf);

        //printf("element_deleted");



    }

}

// ïðîâåðêà íà ïóñòîòó ñïèñêà

int isEmpty(struct list* l)

{

    if(l->head == NULL)

    {

        return 1;

    }

    return 0;

}

// âñòàâêà çíà÷åíèÿ â êîíåö ñïèñêà, âåðíóòü 0 åñëè óñïåøíî

int push_back_l(struct list* l, struct node *value)

{

    //printf("1");

    struct node_l *buf;

    buf = l->tail;



    //printf("2");

    struct node_l *nd;

    // âûäåëåíèå ïàìÿòè ïîä êîðåíü ñïèñêà

    nd = (struct node_l*)malloc(sizeof(struct node_l));

    nd->next = NULL;

    nd->value = value;



    //printf("3");

    l->tail = nd;

    if(l->head == NULL)

    {

        l->head = nd;

    }

    else

    {

        buf->next = nd;

    }



    //printf("4");

    if(l->tail->value == value)

    {

        //printf("end");

        return 0;

    }

    return 1;

}

// âûâåñòè 'ktvtyns èç ñïèñêà â ïðÿìîì ïîðÿäêå

struct node* give(struct list* l)

{

    struct node_l *buf;

    buf = l->head;

    l->head = l->head->next;

    struct node *viv;

    viv = buf->value;

    free(buf);

    return viv;



}



/////////////////////////////////////////////////////////////////////



struct node

{

    int value;

    struct node *mom;

    struct node *right;

    struct node *left;

};

/* ñòðóêòóðà äëÿ õðàíåíèÿ äåðåâà. õðàíèò ññûëêó íà êîðåíü

äåðåâà è êîëè÷åñòâî ýëåìåíòîâ â äåðåâå */

struct tree

{

    struct node *root;

    int all;

};

// èíèöèàëèçàöèÿ ïóñòîãî äåðåâà

void init(struct tree* t)

{

    t->root = NULL;

    t->all = 0;

}

//óäàëèòü âñå ýëåìåíòû èç äåðåâà

void clear_node_T(struct node* t)

{

    if (t->left != NULL)

    {

        clear_node_T(t->left);

    }

    if (t->right != NULL)

    {

        clear_node_T(t->right);

    }

    free(t);

}

void clear(struct tree* t)

{

    clear_node_T(t->root);

    t->root = NULL;

    t->all = 0;

}



/* ïîèñê ýëåìåíòà ïî çíà÷åíèþ. âåðíóòü 0 åñëè ýëåìåíò íàéä

åí è ññûëêó íà íàéäåííéû ýëåìåíò â ïåðåìåííóþ n åñëè n !=

NULL. â ñëó÷àå åñëè ýëåìåíò íå íàéäåí âåðíóòü 1

*/

int find(struct tree* t, int value, struct node** viv)

{

    struct node *buf;

    buf = t->root;

    if (buf != NULL)

    {

        while(buf != NULL && buf->value != value)

        {

            if(value > buf->value)

            {

                buf = buf->right;

            }

            else if(value < buf->value)

            {

                buf = buf->left;

            }

        }

    }



    if (buf != NULL)

    {

        *viv = buf;

        return 0;

    }

    return 1;

}

/* âñòàâêà çíà÷åíèÿ â äåðåâî. âåðíóòü 0 åñëè âñòàâêà âûïîë

íåíà óñïåøíà,

1 åñëè ýëåìåíò óæå ñóùåñòâóåò

2 åñëè íå óäàëîñü âûäåëèòü ïàìÿòü äëÿ íîâîãî ýëåìåíòà

*/

int insert(struct tree* t, int value)

{

    struct node *branch;

    branch = (struct node*)malloc(sizeof(struct node));

    if(branch == NULL)

    {

        return 2;

    }

    branch->value = value;

    branch->right = NULL;

    branch->left = NULL;



    if (t->root == NULL)

    {

        branch->mom = NULL;

        t->root = branch;

        t->all++;

        return 0;

    }

    else

    {

        struct node *buf, *ma;

        buf = t->root;

        while(buf != NULL)

        {

            if(value > buf->value)

            {

                ma = buf;

                buf = buf->right;

            }

            else if (value < buf->value)

            {

                ma = buf;

                buf = buf->left;

            }

            else{return 1;}

        }

        branch->mom = ma;

        if (ma->value > value)

        {

            ma->left = branch;

        }

        if (ma->value < value)

        {

            ma->right = branch;

        }

        t->all++;

        return 0;

    }

}

/* óäàëèòü ýëåìåíò èç äåðåâà. âåðíóòü 0 åñëè ýëåìåíò áûë ó

äàëåí è 1 åñëè íåò ýëåìåíòà ñ óêàçàííûì çíà÷åíèåì */

void findMax (struct node *t, struct node** n)

{

    struct node *buf;

    buf = t;

    if (buf != NULL)

    {

        while(buf->right != NULL)

        {

            buf = buf->right;

        }

    }

    *n = buf;

}

void findMin (struct node *t, struct node** n)

{

    struct node *buf;

    buf = t;

    if (buf != NULL)

    {

        while(buf->left != NULL)

        {

            buf = buf->left;

        }

    }

    *n = buf;

}

 int remove_tree(struct tree* t, int value)

{

    int i;

    struct node *fi, *buf, *c_mom, *c_right, *c_left;

    fi = NULL;

    buf = NULL;

    i = find(t, value, &fi);



    if (i == 0)

    {

        t->all--;

        if(fi->right != NULL)

        {



            //printf("%d", fi->right->value);

            findMin(fi->right, &buf);

            c_mom = buf->mom;

            c_right = buf->right;

            c_left = buf->left;

            //ñâÿçü ñ ðîääèòåëåì

            buf->mom = fi->mom;

            if (fi->mom != NULL)

            {

                if(fi->mom->value > fi->value)

                {

                    fi->mom->left = buf;

                }

                else

                {

                    fi->mom->right = buf;

                }

            }

            else

            {

                t->root = buf;

            }

            //ñâÿçü ñ ëåâûì

            buf->left = fi->left;

            if (fi->left != NULL)

            {

                fi->left->mom = buf;

            }

            //ñâÿçü ñ ïðàâûì

            if(fi->right != buf)

            {

                buf->right = fi->right;

            }

            else if (buf->right != NULL)

            {

                buf->right = buf->right;

            }

            else

            {

                buf->right = NULL;

            }

            if(buf->right != NULL)

            {

                buf->right->mom = buf;

            }

//buf->right = NULL;

            //âîñòàíîâëåíèå ïðîáåëà

            if(fi != c_mom)

            {

                 if(c_right != NULL)

                {

                    c_right->mom = c_mom;

                }

                if (c_mom != NULL)

                {

                    c_mom->left = c_right;

                }

            }

//buf->right = NULL;

            //

            free(fi);

            return 0;

        }

        else if (fi->left != NULL)

        {



            //printf("%d", fi->right->value);

            findMax(fi->left, &buf);

            c_mom = buf->mom;

            c_right = buf->right;

            c_left = buf->left;

            //ñâÿçü ñ ðîääèòåëåì

            buf->mom = fi->mom;

            if (fi->mom != NULL)

            {

                 if(fi->mom->value > fi->value)

                {

                    fi->mom->left = buf;

                }

                else

                {

                    fi->mom->right = buf;

                }

            }

            else

            {

                t->root = buf;

            }

            //ñâÿçü ñ ïðàâûì

            buf->right = fi->right;

            if (fi->right != NULL)

            {

                fi->right->mom = buf;

            }

            //ñâÿçü ñ ëåâûì

            if(fi->left != buf)

            {

                buf->left = fi->left;

            }

            else if (buf->left != NULL)

            {

                buf->left = buf->left;

            }

            else

            {

                buf->left = NULL;

            }

            if(buf->left != NULL)

            {

                buf->left->mom = buf;

            }

            //âîñòàíîâëåíèå ïðîáåëà

            if(fi != c_mom)

            {

                if(c_left != NULL)

                {

                    c_left->mom = c_mom;

                }

                if (c_mom != NULL)

                {

                    c_mom->right = c_left;

                }

            }

            //

            free(fi);

            return 0;

        }

        else

        {

            if(fi->mom->value > fi->value)

            {

                fi->mom->left = NULL;

            }

            else

            {

                fi->mom->right = NULL;

            }

            free(fi);

            return 0;

        }

    }

    return 1;

}



/* óäàëèòü ìèíèìàëüíûé ýëåìåíò èç ïîääåðåâà, êîðíåì êîòîðî

ãî ÿâëÿåòñÿ n. âåðíóòü çíà÷åíèå óäàëåííîãî ýëåìåíòà */

int removeMin(struct node* n, struct tree *t)

{

    if (n == NULL)

    {

        return -1;

    }

    struct node *buf;

    int viv;

    findMin(n, &buf);

    viv = buf->value;

    remove_tree(t, viv);

    return viv;

}

/* âûïîëíèòü ïðàâîå âðàùåíèå ïîääåðåâà, êîðíåì êîòîðîãî ÿâ

ëÿåòñÿ n. âåðíóòü 0 ïðè óñïåùøíî âûïîëíåíèå îïåðàöèè è 1 â

ñëó÷àå åñëè âðàùåíèå íåâîçìîæíî */

int rotateRight(struct tree *t, struct node *n)

{

    struct node *fi, *buf, *c_mom, *c_left;

    fi = n;

    buf = NULL;



    if (fi->left != NULL)

    {

        //printf("%d", fi->right->value);

        findMax(fi->left, &buf);

        c_mom = buf->mom;

        c_left = buf->left;

        //ñâÿçü ñ ðîääèòåëåì

        buf->mom = fi->mom;

        if (fi->mom != NULL)

        {

             if(fi->mom->value > fi->value)

            {

                fi->mom->left = buf;

            }

            else

            {

                fi->mom->right = buf;

            }

        }

        else

        {

            t->root = buf;

        }

        //ñâÿçü ñ ïðàâûì

        buf->right = fi;

        fi->mom = buf;

        //ñâÿçü ñ ëåâûì

        if(fi->left != buf)

        {

            buf->left = fi->left;

        }

        else if (buf->left != NULL) //////????

        {

            buf->left = buf->left;

        }

        else

        {

            buf->left = NULL;

        }

        ////////////////////////////////??????^^

        if(buf->left != NULL)

        {

            buf->left->mom = buf;

        }

        //âîñòàíîâëåíèå ïðîáåëà

        if(fi != c_mom)

        {

             if(c_left != NULL)

            {

                c_left->mom = c_mom;

            }

            if (c_mom != NULL)

            {

                c_mom->right = c_left;

            }

        }

        //çà÷èñòêà ëåâîãî óêàçàòåëÿ

        fi->left = NULL;

        //

        return 0;

    }

    else

    {

        return 1;

    }

}

/* âûïîëíèòü ëåâîå âðàùåíèå ïîääåðåâà, êîðíåì êîòîðîãî ÿâë

ÿåòñÿ n. âåðíóòü 0 ïðè óñïåùøíî âûïîëíåíèå îïåðàöèè è 1 â

ñëó÷àå åñëè âðàùåíèå íåâîçìîæíî */

int rotateLeft(struct tree *t, struct node *n)

{

    struct node *fi, *buf, *c_mom, *c_right;

    fi = n;

    buf = NULL;



    if (fi->right != NULL)

    {

        //printf("%d", fi->right->value);

        findMin(fi->right, &buf);

        c_mom = buf->mom;

        c_right = buf->right;

        //ñâÿçü ñ ðîääèòåëåì

        buf->mom = fi->mom;

        if (fi->mom != NULL)

        {

             if(fi->mom->value > fi->value)

            {

                fi->mom->left = buf;

            }

            else

            {

                fi->mom->right = buf;

            }

        }

        else

        {

            t->root = buf;

        }

        //ñâÿçü ñ ëåâûì

        buf->left = fi;

        fi->mom = buf;

        //ñâÿçü ñ ïðàâûì

        if(fi->right != buf)

        {

            buf->right = fi->right;

        }

        else if (buf->right != NULL) //////????

        {

            buf->right = buf->right;

        }

        else

        {

            buf->right = NULL;

        }

        ////////////////////////////////??????^^

        if(buf->right != NULL)

        {

            buf->right->mom = buf;

        }

        //âîñòàíîâëåíèå ïðîáåëà

        if(fi != c_mom)

        {

             if(c_right != NULL)

            {

                c_right->mom = c_mom;

            }

            if (c_mom != NULL)

            {

                c_mom->left = c_right;

            }

        }

        //çà÷èñòêà ïðàâîãî óêàçàòåëÿ

        fi->right = NULL;

        //

        return 0;

    }

    else

    {

        return 1;

    }

}

/* âûâåñòè âñå çíà÷åíèÿ èç ïîääåðåâà êîðíåì êîòîðîãî ÿâëÿå

òñÿ n ïî óðîâíåì, íà÷èíàÿ ñ êîðíÿ. êàæäûé óðîâåíü âûâîäèòñ

ÿ íà ñâîåé ñòðîêå. ýëåìåíòû â ñòðîêå ðàçäåëÿþòñÿ ïðîáåëîì.

åñëè íà óêàçàííîì ìåñòå íåò ýëåìåíòà, çàìåíèòü åãî çíà÷åí

èåì '_'. Åñëè äåðåâî ïóñòî âûâåñòè '-' */

void print(struct node* n)

{

    struct list *li1;

    li1 = (struct list*)malloc(sizeof(struct list));

    init_l(li1);

    struct list *li2;

    li2 = (struct list*)malloc(sizeof(struct list));

    init_l(li2);

    //

    push_back_l(li1,n);

    //

    int fp, sp;

    fp = 1;

    sp= 1;

    while(sp == 1)

    {

        sp = 0;

        fp = 1;

        while(fp == 1)

        {

            fp = 0;

//printf("()");

            if(!isEmpty(li1))

            {

//printf("io");

                fp = 1;

                //

                if (li1->head->value != NULL)

                {

                    if (li1->head->value->left != NULL)

                    {

                        sp = 1;



                    }

                    push_back_l(li2,li1->head->value->left);

//printf("2");

                    if (li1->head->value->right != NULL)

                    {

                        sp = 1;

                    }

                    push_back_l(li2,li1->head->value->right);

                }

                else

                {

                    push_back_l(li2, NULL);

                    push_back_l(li2, NULL);

                }



//printf("3");

                struct node *viv;

                viv = give(li1);

//printf("4");

                if (viv != NULL)

                {

                    printf("%d", viv->value);

                    /*//^

                    if(viv->left != NULL)

                    {

                        printf("%d", viv->left->value);

                    }

                    else

                    {

                        printf("N");

                    }

                     if(viv->right != NULL)

                    {

                        printf("%d", viv->right->value);

                    }

                    else

                    {

                        printf("N");

                    }

                     if(viv->mom != NULL)

                    {

                        printf("%d", viv->mom->value);

                    }

                    else

                    {

                        printf("N");

                    }

                    *///^

                }

                else

                {

                    printf("_");

                }

//printf("5");

            }



            if(!isEmpty(li1))

            {

                printf(" ");

            }

            else

            {

                fp = 0;

                printf("\n");

                struct list *buf;

                buf = li1;

                li1 = li2;

                li2 = buf;

                clear_l(li2);

            }

        }

    }

}

// âûâåñòè âñå çíà÷åíèÿ äåðåâà t, àíàëîãè÷íî ôóíêöèè print (Åñëè äåðåâî ïóñòî âûâåñòè '-')

void printTree(struct tree* t)

{

    if(t->root == NULL)

    {

        printf("-\n");

    }

    else

    {

        print(t->root);

    }

}

///////////////////////////

void check_all()

{

    struct tree *myt;

    myt = (struct tree*) malloc(sizeof(struct tree));



    //printf("Hello!\n");



    init(myt);



    int q;

    for (int i = 0; i < 7;i++)

    {

        scanf("%d", &q);

        q = insert(myt, q);

        //printf ("polojili? - %d \n", !q);

    }

    printTree(myt);

    remove_tree(myt, 1);

    printTree(myt);

    remove_tree(myt, 5);

    printTree(myt);

}



int main()

{

    //check_all();



    ////

    //1

    int sc;

    struct tree *myt;

    myt = (struct tree*) malloc(sizeof(struct tree));

    init(myt);

    for(int i = 0; i < 4; i++)

    {

        scanf("%d", &sc);

        insert(myt, sc);

    }

    printTree(myt);

    //3

    for(int i = 0; i < 3; i++)

    {

        scanf("%d", &sc);

        insert(myt, sc);

    }

    printTree(myt);

    //5

    struct node *w;

    w = NULL;

    scanf("%d", &sc);

    find(myt, sc, &w);

    if (w != NULL)

    {

        if(w->mom != NULL)

        {

            printf("%d ", w->mom->value);

        }

        else{printf("_ ");}

        if(w->left != NULL)

        {

            printf("%d ", w->left->value);

        }

        else{printf("_ ");}

        if(w->right != NULL)

        {

            printf("%d", w->right->value);

        }

        else{printf("_");}

    }

    else{printf("-");}

    //6

    printf("\n");

    w = NULL;

    scanf("%d", &sc);

    find(myt, sc, &w);

    if (w != NULL)

    {

        if(w->mom != NULL)

        {

            printf("%d ", w->mom->value);

        }

        else{printf("_ ");}

        if(w->left != NULL)

        {

            printf("%d ", w->left->value);

        }

        else{printf("_ ");}

        if(w->right != NULL)

        {

            printf("%d", w->right->value);

        }

        else{printf("_");}

    }

    else{printf("-");}

    printf("\n");

    //7

    scanf("%d", &sc);

    remove_tree(myt, sc);

    printTree(myt);

    //9

    while(!rotateLeft(myt, myt->root))

    {

        rotateLeft(myt, myt->root);

    }

    printTree(myt);

    //11

    while(!rotateRight(myt, myt->root))

    {

        rotateRight(myt, myt->root);

    }

    printTree(myt);

    //13

    printf("%d", myt->all);

    //14

    clear(myt);

    printf("\n");

    //15

    printTree(myt);

    ////

    return 0;

}
