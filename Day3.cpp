#include <iostream>
#include <iomanip>

setlocale(LC_ALL, "Russian");
using namespace std;

const float g = 9.8;

struct Shar 
{
	float h, v, a, t;
	Shar* next;
};

void init(Shar* head)
{
	head->h = 0;
	head->v = 0;
	head->a = 0;
	head->t = 0;
	head->next = NULL;
}

void WriteShar(Shar* ls, float h, float v, float a, float t) 
{
	Shar* b = ls;
	while (b->next != NULL)
		b = b->next;

	b->h = h;
	b->v = v;
	b->a = a;
	b->t = t;
	b->next = new Shar;
	init(b->next);
};

Shar* move(float h, float v, float dt) 
{
	Shar* output = new Shar;
	init(output);

	float a = g;
	float up_t, down_t, max_h;
	if (v > 0) // vverh
	{ 
		up_t = v / a;
		float dh = v * v / (2 * a);
		max_h = h + dh;
		down_t = sqrt(2 * max_h / a);

		WriteShar(output, h, v, -g, 0);
	}
	else // vniz
	{ 
		up_t = 0;
		max_h = h;
		down_t = (-abs(v) + sqrt(v * v + 2 * a * h)) / a;
		
		WriteShar(output, h, v, g, 0);
	}

	double ct = dt; // vverh za dt
	while (ct <= up_t) 
	{
		h += v * dt - a * dt * dt / 2;
		v -= a * dt;
		WriteShar(output, h, v, -g, ct);
		ct += dt;
	} 
	v = a * (ct - up_t);
	h = max_h - a * (ct - up_t) * (ct - up) / 2;
	WriteShar(output, h, -v, -g, ct);
	ct += dt; // vniz za dt
	while (ct < up + down_t) {
		h -= v * dt + a * dt * dt / 2;
		v += a * dt;
		WriteShar(output, h, -v, -g, ct);
		ct += dt;
	}
	WriteShar(output, 0, 0, 0, ct);
	cout << "Полёт окончен" << endl;
	return output;
};

void print(Shar* shar, float t) 
{
	cout << "t =  /  h =  /  v =  / a =" << endl;

	Shar* cur = shar;
	while (cur->next != NULL && cur->t <= t) 
	{
		cout << setprecision(2);
		cout << (float)cur->t << "\t" << cur->h << "\t" << cur->v << "\t" << cur->a << endl;
		cur = cur->next;
	}
};

void testInit() 
{
	Shar* y = new Shar;
	init(y);
	y->next = new Shar;
	init(y->next);
	if (y->a == 0 && y->next != NULL)
		if (y->next->a == 0 && y->next->next == NULL)
			return 1;
	return 0;
};

void testWriteShar() 
{
	Shar* y = new Shar;
	init(y);

	WriteShar(y, 1.2345, 1, 1, 0.000001);
	WriteShar(y->next, -1, 1000, -1.09876, 1);

	if (y->h == 1.2345 && y->t == 0.000001)
		if (y->next->a == -1.09876 && y->next->v == 1000)
			return 1;

	return 0;
};

void testMove()
{
	WriteShar* out = move(g, 2 * g, 1.0);

	if (out->h - g < 0.001 && out->a == -g && out->v == 2 * g && out->t == 0)	
	{
		out = out->next;
		if (out->h - 2.5 * g < 0.001 && out->a == -g && out->v == g && out->t == 1)	
		{
			out = out->next;
			if (out->h - 3.0 * g < 0.001 && out->a == -g && out->v == 0 && out->t == 2)	
			{
				out = out->next;
				if (out->h - 2.5 * g < 0.001 && out->a == -g && out->v == -g && out->t == 3)	
				{
					out = out->next;
					if (out->h - g < 0.001 && out->a == -g && out->v == -2 * g && out->t == 4)	
					{
						out = out->next;
						if (out->h == 0 && out->a == 0 && out->v == 0 && out->t == 5)	
						{
							return 1;
						}
					}
				}
			}
		}
	}

	return 0;
}












