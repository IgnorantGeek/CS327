#ifndef OBJECT_DESCRIPTIONS_H
# define OBJECT_DESCRIPTIONS_H

# include <stdint.h>
# include <vector>
# include <string>
# include "dice.h"
# include "object_type.h"

typedef struct dungeon dungeon_t;

uint32_t parse_object_descriptions(dungeon_t *d);
uint32_t print_object_descriptions(dungeon_t *d);
uint32_t destroy_object_descriptions(dungeon_t *d);

extern const char object_symbol[];

class object_description 
{
	private:
		std::string name, description;
		object_type_t type;
		uint32_t color;
		dice hit, damage, dodge, defence, weight, speed, attribute, value;
		bool artifact;
		uint32_t rarity;
	public:
		/*what does this stuff under here mean?
		 * This stuff is the "default constructor"*/
		object_description() : name(),    description(), type(objtype_no_type),
		color(0),  hit(),         damage(),
		dodge(),   defence(),     weight(),
		speed(),   attribute(),   value(),
		artifact(false), rarity(0)
	{
	}
		void set(const std::string &name,
				const std::string &description,
				const object_type_t type,
				const uint32_t color,
				const dice &hit,
				const dice &damage,
				const dice &dodge,
				const dice &defence,
				const dice &weight,
				const dice &speed,
				const dice &attrubute,
				const dice &value,
				const bool artifact,
				const uint32_t rarity);
		std::ostream &print(std::ostream &o); //what is this?
		/* Need all these accessors because otherwise there is a *
		 * circular dependancy that is difficult to get around.  */
		inline const std::string &get_name() const { return name; }
		inline const std::string &get_description() const { return description; }
		inline const object_type_t get_type() const { return type; }
		inline const uint32_t get_color() const { return color; }
		inline const dice &get_hit() const { return hit; }
		inline const dice &get_damage() const { return damage; }
		inline const dice &get_dodge() const { return dodge; }
		inline const dice &get_defence() const { return defence; }
		inline const dice &get_weight() const { return weight; }
		inline const dice &get_speed() const { return speed; }
		inline const dice &get_attribute() const { return attribute; }
		inline const dice &get_value() const { return value; }
};

std::ostream &operator<<(std::ostream &o, object_description &od);

uint32_t convert_to_items(dungeon_t *d); 

#endif
