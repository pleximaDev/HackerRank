#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


class Box
{
 public:
    // void Box(int, int, int) const;
    Box() {}
    Box(int length, int breadth, int height) : l(length), b(breadth), h(height) {}
    Box(Box& B) : l(B.l), b(B.b), h(B.h) {}
    int getLength();
    int getBreadth();
    int getHeight();
    long long CalculateVolume();
    bool operator<(Box& B);
    friend ostream& operator<<(ostream& out, const Box& B);

 private:
    int l{0}, b{0}, h{0};
};

int Box::getLength()
{
    return l;
}
int Box::getBreadth()
{
    return b;
}
int Box::getHeight()
{
    return h;
}
long long Box::CalculateVolume()
{
    return (long long)l * b * h;
}

bool Box::operator<(Box &B)
{
    // bool ret = false;
    if(this -> l < B.l)
        return true;
        // return this -> l < B.l;
    else if(b < B.b && l == B.l)
        return true;
        // return this -> b < B.b && l == B.l;
    else if(h < B.h && b == B.b && l == B.l)
        return true;
        // return this -> h < B.h && b == B.b && l == B.l;
    else return false;
}

ostream& operator<<(ostream& out, const Box& B)
// ostream& Box::operator<<(Box& B)
{
    // return out << this -> l << " " <<  this -> b << " " <<  this -> h << endl;
    
    return out << B.l << " " << B.b << " " << B.h;
    // return cout << B.l << " " << B.b << " " << B.h << '\n';
}



void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
