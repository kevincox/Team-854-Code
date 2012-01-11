/*
#include <Jaguar.h>
#include <Victor.h>

class Motor
{
	enum motorControllerType {
		jaguar,
		victor,
		undefined
	};
	private:
		motorControllerType type;
		union
		{
			Jaguar *jag;
			Victor *vic;
		};
		double mod; ///< The correction factor to apply to the motors.

	public:
		Motor ( motorControllerType type, unsigned int slot, unsigned int channel, double modifier)
		{
			this->type = type;
			this->mod = modifier;

			switch (type)
			{
				case jaguar:
					this->jag = new Jaguar(slot, channel);
					break;
				case victor:
					this->vic = new Victor(slot, channel);
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
					jag->Set(value);
					break;
				case victor:
					vic->Set(value);
					break;
			}
		}
		float get(void)
		{
			switch (type)
			{
				case jaguar:
					return jag->Get();
				case victor:
					return vic->Get();
					return 0;
			}
		}

		void enableDeadbandElimination ( bool enable )
		{
			if ( type == victor ) vic->EnableDeadbandElimination(enable);
		}
};*/
