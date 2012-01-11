/*class Motor
{
	private:
		motorControlerType type;
		union
		{
			int jag;
			//Jaguar jag;
			//Victor vic;
		};
		double mod; ///< The correction factor to apply to the motors.

	public:
		Motor ( motorControlerType type, unsigned int slot, unsigned int channel, double modifier)
		{
			this->type = type;
			this->mod = modifier;

			switch (type)
			{
				case jaguar:
					//this->jag = new Jaguar(slot, channel);
					break;
				case victor:
					//this->vic = new Victor(slot, channel);
					break;
				default:
					this->type = undefined;
			}
		}

		void set(float value)
		{
			value *= mod;

			switch (type)
			{
				case jaguar:
					//jag.Set(value);
					break;
				case victor:
					//vic.Set(value);
					break;
			}
		}
		float get(void)
		{
			switch (type)
			{
				case jaguar:
					//return jag.Get();
				case victor:
					//return vic.Get();
					return 0;
			}
		}

		void enableDeadbandElimination ( bool enable )
		{
			//if ( type == victor ) vic.EnableDeadbandElimination(enable);
		}
};*/

class Wheel
{
		double x; ///< Location of the wheel (in mm)
		double y; ///< Location of the wheel (in mm)
		double rot; ///< rotation of the wheel (in radians)
	public:
		///Diameter of the plysical wheel
		/**
		 * This is the diameter of the physical wheel.  This is used in
		 * calculations of distance.
		 *
		 * \warning Do not modify this value.  It should be set by calling
		 *		Wheel.setDiameter()
		 */
		float diameter;
		///Circumference of the plysical wheel
		/**
		 * This is the circumference of the physical wheel.  This is used in
		 * calculations of distance.
		 *
		 * \warning Do not modify this value.  It should be set by calling
		 *		Wheel.setCircumfrence()
		 */
		float circumfrence;

		Wheel ( double, double, double );

		void setPosition (double x, double y);
		void setRotation ( double rot );
		void setDiameter(double d);
		void setCircumfrence(double d);
};

Wheel::Wheel ( double posx = 0, double posy = 0, double rot = 0 )
{
	setPosition(posx, posy);
	setRotation(rot);

	setDiameter(1);
}

void Wheel::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Wheel::setRotation(double rot)
{
	while ( rot > M_PI ) rot -= M_PI;  // Get the value in range
	while ( rot < -M_PI ) rot += M_PI; //
	this->rot = rot;
}

/// Set's Physical Wheel Diameter
/**
 * @param d Diameter of the physical wheel.
 */
void Wheel::setDiameter(double d)
{
	diameter = d;
	circumfrence = M_PI*d;
}
/// Set's Physical Wheel Circumfrence
/**
 * @param c Circumfrence of the physical wheel.
 */
void Wheel::setCircumfrence(double c)
{
	diameter = c/M_PI;
	circumfrence = c;
}
