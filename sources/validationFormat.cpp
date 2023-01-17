/*
 * \file validationFormat.cpp
 * \brief tout les fonctions permetant de valider les input de l'usager
 * \author Emilio Lemus
 * \date 2022-10-12
 *
 */

#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include "validationFormat.h"

using namespace std;

using std::cout;
using std::endl;
using std::istringstream;


namespace util
{


  /*
   * \brief verifie si un nom est valide ou non
   *
   * \param[in] p_nom soit un nom quelconque (ex: Emilio Lemus)
   * \return un booleen indiquant si le nom (sont format) est bon ou movais
   */

  bool
  validerFormatNom (const string& p_nom)
  {
    bool var = true;
    int len = p_nom.size ();
    if (len > 0)
      {
        string previous_char = p_nom.substr (0, 1);
        if (isalpha (p_nom[0]) && isalpha (p_nom[len - 1]))
          {
            for (int i = 0; i < len; i++)
              {
                if (isalpha (p_nom[i]))
                  {
                    previous_char = p_nom[i];
                    continue;
                  }
                else if ((p_nom[i] == ' ' or p_nom[i] == '-') && isalpha (previous_char[0]))
                  {
                    previous_char = p_nom[i];
                    continue;
                  }
                else
                  {
                    var = false;
                    break;
                  }

              }
          }
        else
          {
            var = false;
          }
      }
    else
      {
        var = false;
      }

    return var;
  }


  /*
   * \brief verifi si un code de type ISSN a un format et une clée valid
   *
   * \param[in] p_issn sois un code quelconque (ex: ISSN 1467-8640)
   * \return un booleen indiquant si le code ISSN est bon ou mauvais
   */

  bool
  validerCodeIssn (const string & p_issn)
  {

    bool var = true;
    if (p_issn.size () == 14)
      {
        string start = p_issn.substr (0, 5);
        string first_numbs = p_issn.substr (5, 4);
        string last_numbs = p_issn.substr (10, 4);
        string all_numbs = first_numbs + last_numbs;
        string copy1;

        int a = 0;
        int ponde = 8;
        int total = 0;
        int last_num = 0;

        if (p_issn[9] == '-' && start == "ISSN ")
          {
            //valider si format est bon avec isdigit() et calcul de clé
            for (int i = 0; i < 8; i++)
              {

                if (isdigit (all_numbs[i]) && i != 7)
                  {
                    //trouver moyen d'enlever le if qui suit

                    copy1 = all_numbs[i];
                    a = atoi (copy1.c_str ());
                    total = total + a*ponde;

                  }
                else if (i == 7)
                  {
                    if (isdigit (all_numbs[i]))
                      {
                        copy1 = all_numbs[i];
                        last_num = atoi (copy1.c_str ());
                        if (last_num == 0)
                          {
                            last_num = 11;
                          }
                      }
                    else if (all_numbs[i] == 'X')
                      {
                        last_num = 10;
                      }
                    else
                      {
                        var = false;
                      }

                  }
                else
                  {
                    var = false;
                  }
                ponde--;
              }
            //verify if the last number is correct
            if (11 - total % 11 != last_num)
              {
                var = false;
              }


          }
        else
          {
            var = false;
          }
      }
    else
      {
        var = false;
      }

    return var;
  }


  /*
   * \brief verifie si un code de type ISBN a un format et une clée valide
   *
   * \param[in] p_isbn sois un code quelconque (ex: ISBN 978-2-7605-5379-8)
   * \return un booleen indiquant si le code ISBN est bon ou mauvais
   */

  bool
  validerCodeIsbn (const std::string & p_isbn)
  {
    bool var = false;
    if (p_isbn.size () == 22)
      {
        if ((p_isbn.substr (0, 9) == "ISBN 978-" or p_isbn.substr (0, 9) == "ISBN 979-")
            && p_isbn[20] == '-' && isdigit (p_isbn[21]))
          {
            string copy1 = p_isbn.substr (5, 17);
            for (int i = 0; i < copy1.size (); i++)
              {
                if (copy1[i] == '-')
                  {
                    copy1[i] = ' ';
                  }
              }
            int total = 0;
            istringstream my_str (copy1);
            int intro;
            int domaine;
            int editeur;
            int num_publication;
            my_str >> intro;
            my_str >> domaine;
            my_str >> editeur;
            my_str >> num_publication;

            if ((0 <= domaine && domaine <= 5) or(domaine == 7)or(80 <= domaine && domaine <= 94)
                or(950 <= domaine && domaine <= 989)or(9900 <= domaine && domaine <= 9989)or(99900 <= domaine && domaine <= 99999))
              {
                if ((0 <= editeur && editeur <= 19)or(200 <= editeur && editeur <= 699)or(7000 <= editeur && editeur <= 8499)
                    or(85000 <= editeur && editeur <= 89999)or(900000 <= editeur && editeur <= 949999) or(9500000 <= editeur && editeur <= 9999999))
                  {
                    int factor = 1;
                    int num = 0;
                    string convert;

                    for (int j = 0; j < p_isbn.size (); j++)
                      {
                        if (isdigit (p_isbn[j]) && j != 21)
                          {
                            convert = p_isbn[j];
                            num = atoi (convert.c_str ());
                            total += num*factor;
                          }
                        if (j == 21)
                          {
                            convert = p_isbn[j];
                            num = atoi (convert.c_str ());
                          }
                        if (factor == 1 && isdigit (p_isbn[j]))
                          {
                            factor = 3;
                          }
                        else if (factor == 3 && isdigit (p_isbn[j]))
                          {
                            factor = 1;
                          }

                      }
                    if (10 - (total % 10) == 10)
                      {
                        num = 10;
                      }
                    if (10 - (total % 10) == num)
                      {
                        var = true;
                      }
                  }
              }
          }
      }
    return var;
  }


} // namespace util
