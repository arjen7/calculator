#include "calculator.h"
#include "ui_calculator.h"

calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);
}

calculator::~calculator()
{
    delete ui;
}
calculator::Tree *newTree(QString key){
   calculator::Tree* x= new calculator::Tree;
    x->key= key;
    return x;
}
void calculator::equevec(){
    if(!vec.empty()){
        Tree *root= newTree("root");
        for (unsigned int var = 0; var < vec.size(); var++) {
            root->child.push_back(newTree(vec.at(var)));
        }
        equeTree(root);
    }
}
void calculator::equeTree(Tree* root){
    for ( unsigned int  var = 0; var<root->child.size() ; var ++) {
        if(root->child[var]->key=="("){
            int counterleft=1,counterright=0;
            for (unsigned int x = var+1; x < root->child.size(); ) {
                if(root->child[x]->key==")")
                    counterright++;
                  if(root->child[x]->key=="(")
                      counterleft ++;
                  if(counterleft!=counterright){
                      root->child[var]->child.push_back(newTree(root->child[x]->key));
                      root->child.erase(root->child.begin()+x);
                  }
                  else {
                      root->child.erase(root->child.begin()+x);
                      if(counterleft>1)
                          equeTree(root->child[var]);
                      root->child[var]->key=eque(root->child[var]);
                      root->child[var]->child.clear();
                      break;
                  }
             }
        }
    }
    root->key=eque(root);
    root->child.clear();
    ui->label->setText(root->key);
    vec.clear();
    vec.push_back(root->key);
}
QString calculator::eque(Tree* root){
    for (unsigned int var = 0; var < root->child.size(); var++) {

        if(root->child[var]->key=="sin"){
            root->child[var]->key=QString::number(sin(root->child[var+1]->key.toDouble()));
            root->child.erase(root->child.begin()+var+1);
        }
        if(root->child[var]->key=="cos"){
            root->child[var]->key=QString::number(cos(root->child[var+1]->key.toDouble()));
            root->child.erase(root->child.begin()+var+1);
        }
        if(root->child[var]->key=="tan"){
            root->child[var]->key=QString::number(tan(root->child[var+1]->key.toDouble()));
            root->child.erase(root->child.begin()+var+1);
        }
        if(root->child[var]->key=="sqrt"){
            root->child[var]->key=QString::number(sqrt(root->child[var+1]->key.toDouble()));
            root->child.erase(root->child.begin()+var+1);
        }

    }

    for (unsigned int var = 0; var < root->child.size(); var++) {
        if(root->child[var]->key=="^"){
            root->child[var-1]->key=QString::number(pow(root->child[var-1]->key.toDouble(),root->child[var+1]->key.toDouble()));
            root->child.erase(root->child.begin()+var);
            root->child.erase(root->child.begin()+var);
            var--;
        }

        if(root->child[var]->key=="*"){
            root->child[var-1]->key=QString::number(root->child[var-1]->key.toDouble()*root->child[var+1]->key.toDouble());
            root->child.erase(root->child.begin()+var);
            root->child.erase(root->child.begin()+var);
            var--;
        }
        if(root->child[var]->key=="/"){
            root->child[var-1]->key=QString::number(root->child[var-1]->key.toDouble()/root->child[var+1]->key.toDouble());
            root->child.erase(root->child.begin()+var);
            root->child.erase(root->child.begin()+var);
            var--;
        }

    }

    for (unsigned int var = 0; var < root->child.size(); var++) {

        if(root->child[var]->key=="-"){
            if(var==0){
                root->child[var]->key=QString::number(root->child[var+1]->key.toDouble()*(-1));
                root->child.erase(root->child.begin()+var+1);}
            else{
                root->child[var-1]->key=QString::number(root->child[var-1]->key.toDouble()-root->child[var+1]->key.toDouble());
                root->child.erase(root->child.begin()+var);
                root->child.erase(root->child.begin()+var);
                var--;
            }
        }
        if(root->child[var]->key=="+"){
            root->child[var-1]->key=QString::number(root->child[var-1]->key.toDouble()+root->child[var+1]->key.toDouble());
            root->child.erase(root->child.begin()+var);
            root->child.erase(root->child.begin()+var);
            var--;
        }
    }
    return root->child.front()->key;
}
void calculator::equestring(QString x)
{
    if(vec.empty())
    {
         vec.push_back(x);
    }
    else if(x.back().isDigit()||x.back()=='.'){
        if (vec.back().back().isDigit()||vec.back().back()=='.')
         {
             vec.back() += x;
         }
        else
            vec.push_back(x);
    }
    else
     {
        vec.push_back(x);

     }
    text();
}
int calculator::exceptionsfind(){

    if(vec.size()>1){
        for (unsigned int var = 0; var < vec.size()-2; ++var) {
            if(vec.at(var)=="("&&vec.at(var+1)=="-"){
                vec.at(var+1)=QString::number(vec.at(var+2).toDouble()*(-1));
                vec.erase(vec.begin()+var+2);
            }
            if(vec.at(var).back().isDigit()&&vec.at(var+1).back().isDigit())
                return 0;
        }
    }
    return 1;
}
void calculator::text(){
    QString mylist;
    if(!vec.empty())
    {
        for (unsigned int var = 0; var < vec.size(); var++)
        {
            mylist+=vec.at(var);
        }
        ui->label->setText(mylist);
    }
    else
        ui->label->clear();
}

void calculator::on_pushButton_0_clicked()
{
    equestring("0");
}


void calculator::on_pushButton_1_clicked()
{
    equestring("1");
}


void calculator::on_pushButton_2_clicked()
{
    equestring("2");
}


void calculator::on_pushButton_3_clicked()
{
    equestring("3");
}


void calculator::on_pushButton_4_clicked()
{
    equestring("4");
}


void calculator::on_pushButton_5_clicked()
{
    equestring("5");
}


void calculator::on_pushButton_6_clicked()
{
    equestring("6");
}


void calculator::on_pushButton_7_clicked()
{
    equestring("7");
}


void calculator::on_pushButton_8_clicked()
{
    equestring("8");
}


void calculator::on_pushButton_9_clicked()
{
    equestring("9");
}


void calculator::on_butonAc_clicked()
{
    vec.clear();
    ui->label->clear();
}


void calculator::on_butonBc_clicked()
{
    if(!vec.empty()){
        if(vec.back().size()>1){
            if (vec.back().back()=='0')

                 vec.back().chop(1);

            else if(vec.back().back()=='.')

                vec.back().chop(1);

            else if(0<vec.back().toDouble())

                vec.back().chop(1);

            else
                vec.pop_back();
        }
        else
            vec.pop_back();
        text();
   }
}


void calculator::on_butonPoint_clicked()
{
    if(!vec.empty()){
        equestring(".");
        if(1<vec.back().count('.')){
         on_butonBc_clicked();}
    }

}


void calculator::on_bracketsLeft_clicked()
{
    equestring("(");
}


void calculator::on_bracketsRight_clicked()
{
    equestring(")");
}


void calculator::on_butonMultiply_clicked()
{
    equestring("*");
}


void calculator::on_butonDivide_clicked()
{
    equestring("/");
}


void calculator::on_butonLess_clicked()
{
    if(!vec.empty()&&!vec.back().back().isDigit()&&(vec.back()!="("))
        on_bracketsLeft_clicked();
    equestring("-");
}


void calculator::on_butonPlus_clicked()
{
    equestring("+");
}


void calculator::on_butonPow_clicked()
{
    equestring("^");
}


void calculator::on_butonSqrt_clicked()
{
    equestring("sqrt");
    on_bracketsLeft_clicked();
}


void calculator::on_butonSin_clicked()
{
    equestring("sin");
    on_bracketsLeft_clicked();
}


void calculator::on_butonCos_clicked()
{
    equestring("cos");
    on_bracketsLeft_clicked();
}


void calculator::on_butonTan_clicked()
{
    equestring("tan");
    on_bracketsLeft_clicked();
}


void calculator::on_butonEque_clicked()
{
    int x=exceptionsfind();
    if(x==1)
        equevec();
    else {
        ui->label->setText("error");
        vec.clear();
    }
}

