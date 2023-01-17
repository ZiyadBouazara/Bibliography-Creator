/*
 * \file OuvrageInterface.h
 * \brief Interface de la classe ouvrage
 * \author Equipe 14
 * \date 2022-11-28
 *
 */

#ifndef _OUVRAGEINTERFACE_H
#define _OUVRAGEINTERFACE_H

#include "ui_OuvrageInterface.h"

/*
 * \brief Classe OuvrageInterface
 */
class OuvrageInterface : public QDialog
{
  Q_OBJECT
public:
  OuvrageInterface ();
  virtual ~OuvrageInterface ();
  std::string reqAuteurs () const;
  std::string reqTitre () const;
  int reqAnnee () const;
  std::string reqIdentifiant () const;
  std::string reqEditeur () const;
  std::string reqVille () const;
  bool entreeSontValide () const;

private slots:
  void valideEnregistrement ();
private:
  Ui::OuvrageInterface widget;
};

#endif /* _OUVRAGEINTERFACE_H */
