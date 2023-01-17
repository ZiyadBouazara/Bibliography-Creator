/*
 * \file BibliographieInterface.h
 * \brief Interface de la classe bibliographie
 * \author Equipe 14
 * \date 2022-11-28
 *
 */

#ifndef _BIBLIOGRAPHIEINTERFACE_H
#define _BIBLIOGRAPHIEINTERFACE_H

#include "ui_BibliographieInterface.h"
#include "ui_JournalInterface.h"
#include "ui_OuvrageInterface.h"
#include "ui_SupprimeReferenceInterface.h"
#include "Bibliographie.h"
#include <vector>

class BibliographieInterface : public QMainWindow
{
  Q_OBJECT
public:
  BibliographieInterface ();
  virtual ~BibliographieInterface ();

private slots:
  void dialogJournal ();
  void dialogOuvrage ();
  void dialogSupprime ();




private:
  Ui::BibliographieInterface widget;
  biblio::Bibliographie m_biblio;
  void ajouterJournal (const std::string& p_auteurs, const std::string& p_titre,
                       const unsigned int& p_annee, const std::string& p_identifiant,
                       const std::string& p_nom, const unsigned int& p_volume,
                       const unsigned int& p_numero, const unsigned int& p_page);

  void ajouterOuvrage (const std::string& p_auteurs, const std::string& p_titre,
                       const unsigned int& p_annee, const std::string& p_identifiant,
                       const std::string& p_editeur, const std::string& p_ville);
  void supprimeReference (const std::string& p_identifiant);
};

#endif /* _BIBLIOGRAPHIEINTERFACE_H */
