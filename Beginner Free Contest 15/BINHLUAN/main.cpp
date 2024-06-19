#include <bits/stdc++.h>
using namespace std;
#define double long double
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> int sgn(T x)
{
    return (x > 0) - (x < 0);
}
template<class T>
struct Point
{
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const
    {
        return tie(x,y) < tie(p.x,p.y);
    }
    bool operator==(P p) const
    {
        return tie(x,y)==tie(p.x,p.y);
    }
    P operator+(P p) const
    {
        return P(x+p.x, y+p.y);
    }
    P operator-(P p) const
    {
        return P(x-p.x, y-p.y);
    }
    P operator*(T d) const
    {
        return P(x*d, y*d);
    }
    P operator/(T d) const
    {
        return P(x/d, y/d);
    }
    T dot(P p) const
    {
        return x*p.x + y*p.y;
    }
    T cross(P p) const
    {
        return x*p.y - y*p.x;
    }
    T cross(P a, P b) const
    {
        return (a-*this).cross(b-*this);
    }
    T dist2() const
    {
        return x*x + y*y;
    }
    double dist() const
    {
        return sqrt((double)dist2());
    }
    // angle to x-axis in interval [-pi, pi]
    double angle() const
    {
        return atan2(y, x);
    }
    P unit() const
    {
        return *this/dist();    // makes dist()=1
    }
    P perp() const
    {
        return P(-y, x);    // rotates +90 degrees
    }
    P normal() const
    {
        return perp().unit();
    }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const
    {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
    }
    friend ostream& operator<<(ostream& os, P p)
    {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

typedef Point<double> P;

/**
 * Find m such that |ma|/|mb| = k
 */
pair<P,P> divide(P a,P b,double k)
{
    if (k==1)
        return {(a+b)/2.0,(a+b)/2.0};

    P m1 = a+(b-a)*(k/(k+1.0)); // inner point

    if (k<1)
    {
        P m2 = a - (b-a)*k/(1-k);
        //assert(abs((m2-a).dist()/(m2-b).dist()-k)<eps);
        //assert(abs((m1-a).dist()/(m1-b).dist()-k)<eps);
        return {m1,m2};
    }
    else
    {
        P m2 = b + (b-a)*1/(k-1);
        //assert(abs((m2-a).dist()/(m2-b).dist()-k)<eps);
        //assert(abs((m1-a).dist()/(m1-b).dist()-k)<eps);
        return {m1,m2};
    }

}

bool circleInter(P a,P b,double r1,double r2,pair<P, P>* out)
{
    if (a == b)
    {
        assert(r1 != r2);
        return false;
    }
    P vec = b - a;
    double d2 = vec.dist2(), sum = r1+r2, dif = r1-r2,
           p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
    if (sum*sum < d2 || dif*dif > d2) return false;
    P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
    *out = {mid + per, mid - per};
    return true;
}

template<class P>
double lineDist(const P& a, const P& b, const P& p)
{
    return (double)(b-a).cross(p-a)/(b-a).dist();
}

template<class P>
P lineProj(P a, P b, P p, bool refl=false)
{
    P v = b - a;
    return p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2();
}



template<class P>
vector<P> circleLine(P c, double r, P a, P b)
{
    double h2 = r*r - a.cross(b,c)*a.cross(b,c)/(b-a).dist2();
    if (h2 < 0) return {};
    P p = lineProj(a, b, c), h = (b-a).unit() * sqrt(h2);
    if (h2 == 0) return {p};
    return {p - h, p + h};
}

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2)
{
    auto d = (e1 - s1).cross(e2 - s2);
    if (d == 0) // if parallel
        return {-(s1.cross(e1, s2) == 0), P(0, 0)};
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    return {1, (s1 * p + e1 * q) / d};
}

vector<P> o;
vector<double> r;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    for (int i=0; i<3; i++)
    {
        double x,y,R;
        cin >> x >> y >> R;
        o.push_back(P(x,y));
        r.push_back(R);
    }

    pair<P,P> p1 = divide(o[0],o[1],r[0]/r[1]);
    pair<P,P> p2 = divide(o[1],o[2],r[1]/r[2]);

    if (p1.first==p1.second and p2.first==p2.second)
    {
        P n1 = o[1] - o[0];
        P u1 = P(n1.y,-n1.x);
        P n2 = o[2] - o[1];
        P u2 = P(n2.y,-n2.x);

        pair<int,P> inter = lineInter(p1.first,p1.first+u1,p2.first,p2.first+u2);

        if (inter.first==0)
            return 0;
        else if (inter.first==1)
            cout << setprecision(5) << fixed << inter.second.x << ' ' << inter.second.y << '\n';
    }
    else if ((!(p1.first==p1.second)) and (!(p2.first==p2.second)))
    {
        P c1 = (p1.first+p1.second)*0.5;
        double r1 = (p1.first-p1.second).dist()*0.5;
        P c2 = (p2.first+p2.second)*0.5;
        double r2 = (p2.second-p2.first).dist()*0.5;

        pair<P,P> inter;
        if (circleInter(c1,c2,r1,r2,&inter))
        {
            double angle1 = atan(r[0]/(inter.first-o[0]).dist());
            double angle2 = atan(r[0]/(inter.second-o[0]).dist());
            cout << setprecision(5) << fixed;
            if (angle1>angle2)
                cout << inter.first.x << ' ' << inter.first.y << '\n';
            else
                cout << inter.second.x << ' ' << inter.second.y << '\n';
        }
    }
    else
    {
        P n1 = o[1] - o[0];
        P u1 = P(n1.y,-n1.x);
        P n2 = o[2] - o[1];
        P u2 = P(n2.y,-n2.x);
        P c1 = (p1.first+p1.second)*0.5;
        double r1 = (p1.first-p1.second).dist()*0.5;
        P c2 = (p2.first+p2.second)*0.5;
        double r2 = (p2.second-p2.first).dist()*0.5;

        vector<P> inter;
        if (!(p1.first==p1.second))
            inter = circleLine(c1,r1,p2.first,p2.first+u2);
        else
        {
            //cout << setprecision(5) << fixed << p2.first << ' ' << p2.second << ' ' << c2 << ' ' << r2 << '\n';
            inter = circleLine(c2,r2,p1.first,p1.first+u1);


        }

        double maxAng = -1;
        P cur;
        for (P p: inter)
        {
            double angle = atan(r[0]/(p-o[0]).dist());

            if (angle>maxAng)
            {
                maxAng = angle;
                cur = p;
            }
        }

        if (maxAng!=-1)
        {
            cout << setprecision(5) << fixed << cur.x << ' ' << cur.y << '\n';
        }
    }

    return 0;
}
