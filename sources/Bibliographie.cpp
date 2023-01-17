/*
 * \file Bibliographie.cpp
 * \brief Classe bibliographie
 * \author Emilio Lemus
 * \date 2022-11-28
 *
 */

#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Bibliographie.h"
#include "Reference.h"
#include "ReferenceException.h"


using namespace std;

namespace biblio
{


  /*
   * \brief constructeur de la class
   *
   * \param[in] p_nomBibliographie nom de la bibliographie
   * \pre ne peu pas etre vide
   */

  Bibliographie::Bibliographie (const std::string& p_nomBibliographie)
  : m_nomBibliographie (p_nomBibliographie)
  {

    PRECONDITION (p_nomBibliographie.size () > 0);
    POSTCONDITION (m_nomBibliographie == p_nomBibliographie);
    POSTCONDITION (m_vReferences.empty ())

    INVARIANTS ();
  }


  /*
   * \brief constructeur de la class
   *
   * \param[in] p_bibliographie une bibliographie deja existance
   * \pre bibliographie valid selon les precondition etablie
   */

  Bibliographie::Bibliographie (const Bibliographie& p_bibliographie)
  {

    m_nomBibliographie = p_bibliographie.m_nomBibliographie;
    copierVecteur (p_bibliographie);

    POSTCONDITION (m_nomBibliographie == p_bibliographie.m_nomBibliographie);
    //POSTCONDITION(m_vReferences.empty());
    //POSTCONDITION(m_vReferences == p_bibliographie.m_vReferences);

    INVARIANTS ();
  }


  /*
   * \brief destructeur d'un objet bilbiographie (vidage du vecteur atribue m_vReference)
   */

  Bibliographie::~Bibliographie ()
  {
    viderVecteur ();
  }


  /*
   * \brief surcharge de l'operateur =, assigne une bibliographie deja creer elle courante
   * \param[in] p_bibliographie une autre Bibliographie
   * \return un pointeur vers l'objet bibliographie courant
   */

  Bibliographie& Bibliographie::operator= (const Bibliographie& p_bibliographie)
  {

    m_nomBibliographie = p_bibliographie.reqNomBibliographie ();
    viderVecteur ();
    copierVecteur (p_bibliographie);

    //POSTCONDITION(m_vReferences == p_bibliographie.m_vReferences); //a revoir si necessair

    INVARIANTS ();
    return *this;
  }


  /*
   * \brief Accesseur de l'attributs nomBibliographie
   * \return une string du nom de la bibliographie
   */

  const std::string
  Bibliographie::reqNomBibliographie () const
  {
    return m_nomBibliographie;
  }


  /*
   * \brief Ajoue d'une reference a la bibliographie
   * \param[in] p_nouvelleReference une autre reference deja creer
   */

  void
  Bibliographie::ajouterReference (const biblio::Reference& p_reference)
  {

    if (referenceEstDejaPresente (p_reference))
      {
        throw ReferenceDejaPresenteException ("Cette reference existe deja");
      }
    else
      {
        m_vReferences.push_back (p_reference.clone ());
      }
    POSTCONDITION (referenceEstDejaPresente (p_reference));
    INVARIANTS ();
  }


  /*
   * \brief construction de l'affichage de la bibliographie
   * \return une string avec la bibliographie contruite
   */

  const std::string
  Bibliographie::reqBibliographieFormate () const
  {

    stringstream output;
    output << reqNomBibliographie () << "\n" << "===============================" << "\n";
    int i = 1;
    vector<Reference*>::const_iterator iter;
    for (iter = m_vReferences.begin (); iter != m_vReferences.end (); iter++)
      {
        Reference* refCourante = *iter;
        output << "[" << i << "] " << refCourante->reqReferenceFormate () << "\n";
        i++;
      }
    return output.str ();
  }


  /*
   * \brief verifie si une reference est deja dans la bibliographie
   * \param[in] p_reference une reference quelconque
   * \return un bool qui indique si la reference est dans la bibliographie true si oui false si non
   */

  bool
  Bibliographie::referenceEstDejaPresente (const Reference& p_reference) const
  {
    bool estPres = false;
    vector<Reference*>::const_iterator iter;
    for (iter = m_vReferences.begin (); iter != m_vReferences.end (); iter++)
      {
        Reference* refCourante = *iter;
        if ((*refCourante) == p_reference)
          {
            estPres = true;
          }
      }
    return estPres;
  }


  /*
   * \brief Supprime une reference
   * \param[in] p_identifiant l'identifiant de la reference a supprimer
   */
  void
  Bibliographie::supprimerReference (const string& p_identifiant)
  {
    bool my_bool = false;

    vector<Reference*>::const_iterator it;
    for (it = m_vReferences.begin (); it < m_vReferences.end (); it++)
      {
        if ((*it)->reqIdentifiant () == p_identifiant)
          {
            delete (*it);
            it = m_vReferences.erase (it);
            my_bool = true;
          }
      }
    if (!my_bool)
      {
        std::string message = "La reference voulue n'est pas presente :\n";
        throw ReferenceAbsenteException (message);
      }


    INVARIANTS ();
  }


  /*
   * \brief copie le vecteur d'une bibliographie
   * \param[in] p_bibliographie une bibliographie deja creer
   */

  void
  Bibliographie::copierVecteur (const Bibliographie & p_bibliographie)
  {

    PRECONDITION (m_vReferences.empty ());

    vector<Reference*>::const_iterator iter;
    for (iter = p_bibliographie.m_vReferences.begin (); iter < p_bibliographie.m_vReferences.end (); iter++)
      {
        Reference* refCourante = *iter;
        ajouterReference (*refCourante->clone ());
      }

    INVARIANTS ();
  }


  /*
   * \brief vide le vecteur de la bibliographie et libere la memoir qui etait utiliser
   */

  void
  Bibliographie::viderVecteur ()
  {
    vector<Reference*>::const_iterator iter;
    for (iter = m_vReferences.begin (); iter < m_vReferences.end (); iter++)
      {
        delete *iter; // a revoir (on delete le pointer ou lobjet ??)
      }

    m_vReferences.clear ();
  }


  /*
   * \brief verification de l'invarience des atribues de la bibliographie
   */

  void
  Bibliographie::verifieInvariant () const
  {

    INVARIANT (m_vReferences.size () >= 0);
  }

} // namespace biblio