/*
 * \file Ouvrage.cpp
 * \brief Classe ouvrage
 * \author Emilio Lemus
 * \date 2022-11-28
 *
 */

#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Ouvrage.h"
#include "Reference.h"
#include "validationFormat.h"

using namespace std;
using namespace util;

namespace biblio
{


  /*
   * \brief constructeur de la class
   *
   * \param[in] p_auteurs sois un ou plusieur auteur
   * \pre valide en fonction de util::validerFormatNom
   * \param[in] p_titre
   * \pre ne peu pas etre vide
   * \param[in] p_annee l'année d'édition
   * \pre doit etre supérieur a 0
   * \param[in] p_identifiant est un code ISBN
   * \pre valid selon util::validerCodeIsbn
   * \param[in] p_editeur editeur de l'ouvrage
   * \pre valide en fonction de util::validerFormatNom
   * \param[in] p_ville ville d'edition de l'ouvrage
   * \pre valide en fonction de util::validerFormatNom
   *
   */

  Ouvrage::Ouvrage (const std::string& p_auteurs, const std::string& p_titre,
                    const unsigned int& p_annee, const std::string& p_identifiant,
                    const std::string& p_editeur, const std::string& p_ville)
  : Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_editeur (p_editeur), m_ville (p_ville)
  {

    PRECONDITION (util::validerFormatNom (p_editeur));
    PRECONDITION (p_editeur.size () > 0);
    PRECONDITION (util::validerFormatNom (p_ville));
    PRECONDITION (p_ville.size () > 0);
    PRECONDITION (util::validerCodeIsbn (p_identifiant));

    POSTCONDITION (m_editeur == p_editeur);
    POSTCONDITION (m_ville == p_ville);

    INVARIANTS ();
  }


  /*
   * \brief Accesseur de l'attributs editeur
   * \return une string du nom de l'editeur de l'Ouvrage
   */

  const std::string
  Ouvrage::reqEditeur () const
  {
    return m_editeur;
  }


  /*
   * \brief Accesseur de l'attributs ville
   * \return une string du nom de la ville d'edition de l'Ouvrage
   */

  const string
  Ouvrage::reqVille () const
  {
    return m_ville;
  }


  /*
   * \brief construction de la reference d'un ouvrage
   * \return une string avec la reference d'un ouvrage contruite
   */

  const std::string
  Ouvrage::reqReferenceFormate () const
  {

    stringstream formatage;
    formatage << Reference::reqReferenceFormate () << " " << m_ville
            << " : " << m_editeur << ", " << reqAnnee ()
            << ". " << reqIdentifiant () << ".";

    return formatage.str ();
  }


  /*
   * \brief clonage de l'objet Ouvrage courant
   * \return un pointeur vers un nouvel objet Ouvrage qui est clone de celui courant
   */

  Reference*
  Ouvrage::clone () const
  {

    return new Ouvrage (*this);
  }


  /*
   * \brief verification de l'invarience des atribues de l'Ouvrage
   */

  void
  Ouvrage::verifieInvariant () const
  {
    INVARIANT (m_editeur.length () > 0);
    INVARIANT (validerFormatNom (m_editeur));
    INVARIANT (m_ville.length () > 0);
    INVARIANT (validerFormatNom (m_ville));
    INVARIANT (util::validerCodeIsbn (Reference::reqIdentifiant ()));
  }



} // namespace biblio
