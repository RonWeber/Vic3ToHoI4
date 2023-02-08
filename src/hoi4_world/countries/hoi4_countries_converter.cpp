#include "src/hoi4_world/countries/hoi4_countries_converter.h"

#include <ranges>



std::map<std::string, hoi4::Country> hoi4::CountriesConverter::ConvertCountries(
    const std::map<int, vic3::Country>& source_countries,
    const mappers::CountryMapper& country_mapper,
    const std::map<int, int>& vic3_state_ids_to_hoi4_state_ids)
{
   std::map<std::string, Country> countries;

   for (const auto& source_country: source_countries | std::views::values)
   {
      std::optional<Country> new_country =
          country_converter_.ConvertCountry(source_country, country_mapper, vic3_state_ids_to_hoi4_state_ids);
      if (new_country.has_value())
      {
         countries.emplace(new_country->GetTag(), *new_country);
      }
   }

   return countries;
}