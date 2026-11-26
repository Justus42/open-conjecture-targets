# Steckbriefe der Scouts (ohne Begründungen)

### Arxiv-1
Pfad: FormalConjectures/Arxiv/1609.08688/sIncreasingrTuples.lean
Deklaration: maximalLength_le_strong, Zeile 299 (Markierung `category research open` in Zeile 298)
Quelle: W. T. Gowers, J. Long, „The length of an s-increasing sequence of r-tuples“, Combinatorics, Probability and Computing 30 (2021), 686–721, Conjecture 1.8; arXiv:1609.08688, https://arxiv.org/abs/1609.08688
Aussage: Man betrachtet Folgen von Zahlentripeln mit Einträgen aus 1 bis n, in denen jedes spätere Tripel jedes frühere in mindestens zwei der drei Stellen übertrifft. Die Vermutung sagt, dass eine solche Folge für jedes n höchstens n^(3/2) Glieder haben kann.

### Arxiv-2
Pfad: FormalConjectures/Arxiv/1601.03081/UniqueCrystalComponents.lean
Deklaration: crystals_components_unique, Zeile 122 (Markierung `category research open` in Zeile 121)
Quelle: M. Abrate, S. Barbero, U. Cerruti, N. Murru, „The biharmonic mean“, Mathematical Reports 18 (2016), Definition 5 und Vermutung im Schlussabschnitt; arXiv:1601.03081, https://arxiv.org/abs/1601.03081
Aussage: Eine ungerade Zahl n heißt Kristall, wenn sie sich als Produkt n = a·b mit a, b > 1 schreiben lässt, sodass der Ausdruck B(a,b) = ((a+b)² + (ab+1)²) / (2(a+1)(b+1)) eine ganze Zahl ist. Die Vermutung sagt, dass es für jeden Kristall nur eine einzige solche Zerlegung gibt.

### WikiA-1
Pfad: FormalConjectures/Wikipedia/HyperperfectNumber.lean
Deklaration: HyperperfectNumber.mccranie_odd_hyperperfect_conjecture, Zeile 92 (Markierung `category research open` in Zeile 91)
Quelle: J. S. McCranie, „A Study of Hyperperfect Numbers“, Journal of Integer Sequences 3 (2000), Article 00.1.3, Conjecture 1 (Umkehrung von Theorem 1), https://cs.uwaterloo.ca/journals/JIS/VOL3/mccranie.html
Aussage: Eine Zahl n > 1 heißt k-hyperperfekt, wenn n = 1 + k·(Summe aller Teiler von n außer 1 und n selbst); für k = 1 sind das die vollkommenen Zahlen. Die Vermutung sagt: Für ungerades k > 1 gibt es nur Zahlen der Bauart n = p²·q mit den Primzahlen p = (3k+1)/2 und q = 3k+4.

### Paper-1
Pfad: FormalConjectures/Paper/CatchUpConjecture.lean
Deklaration: CatchUp.value_of_even_mul_succ_self_div_two, Zeile 182 (Markierung Zeile 181)
Quelle: A. Isaksen, M. Ismail, S. J. Brams, A. Nealen, „Catch-Up: A Game in Which the Lead Alternates“, Game & Puzzle Design 1(2), 38–49 (2015); https://mpra.ub.uni-muenchen.de/108784/1/MPRA_paper_108784.pdf
Aussage: Zwei Spieler nehmen abwechselnd Zahlen aus {1, …, N}; wer zurückliegt, nimmt so lange weitere Zahlen, bis er gleichzieht oder führt, und am Ende gewinnt die höhere Summe. Die Vermutung sagt: Ist die Gesamtsumme 1+…+N gerade (N durch 4 teilbar oder mit Rest 3), endet das Spiel bei beidseitig bestem Spiel immer unentschieden.

### Paper-2
Pfad: FormalConjectures/Paper/LatinTableau.lean
Deklaration: LatinTableau.SimpleGraph.LatinTableauConjecture, Zeile 47 (Markierung Zeile 46)
Quelle: T. Y. Chow, M. G. Tiefenbruck, „The Latin Tableau Conjecture“, Electron. J. Combin. 32(2) (2025), #P2.48, https://www.combinatorics.org/ojs/index.php/eljc/article/view/v32i2p48 ; arXiv:2408.04086
Aussage: Die Kästchen eines Young-Diagramms (linksbündige Treppe aus Kästchenzeilen) werden so gefärbt, dass in keiner Zeile und keiner Spalte eine Farbe doppelt vorkommt. Die Vermutung sagt: Es gibt immer eine solche Färbung, bei der für jedes k zugleich die k häufigsten Farben zusammen so viele Kästchen belegen, wie mit k Farben überhaupt möglich ist.

### Paper-3
Pfad: FormalConjectures/Paper/FusibleNumber.lean
Deklaration: FusibleNumber.conj_7_1, Zeile 72 (Markierung Zeile 71)
Quelle: J. Erickson, G. Nivasch, J. Xu, „Fusible numbers and Peano Arithmetic“, Logical Methods in Computer Science 18(3) (2022), Conjecture 7.1; https://arxiv.org/abs/2003.14342
Aussage: Fusible Zahlen entstehen aus 0, indem man immer wieder aus zwei schon erzeugten Zahlen a, b mit Abstand unter 1 die Zahl (a+b+1)/2 bildet. Die Vermutung beschreibt für zwei benachbarte fusible Zahlen x < y genau, wie alle fusiblen Zahlen zwischen x+1 und y+1 entstehen: abschnittsweise durch Verschmelzen eines festen, explizit bekannten Partners mit einer fusiblen Zahl knapp unterhalb von x+1.

### WikiB-1
Pfad: FormalConjectures/Wikipedia/SidorenkoConjecture.lean
Deklaration: tournament_anti_sidorenko_trees_conjecture, Zeile 150 (Attribut; `theorem` in Zeile 151)
Quelle: Fox, Himwich, Mani, Zhou, „Variations on Sidorenko's conjecture in tournaments“, arXiv:2402.08418, Conjecture 1.12; wiederholt als Conjecture 1.1 in He, Mani, Nie, Tung, Wei, arXiv:2512.11222
Aussage: Ein Baum ist ein Netz aus Punkten und Verbindungen ohne Kreis; ein Turnier ist ein Jeder-gegen-jeden mit genau einem Sieger pro Paar. Die Vermutung sagt: Die Verbindungen jedes Baums lassen sich so mit Pfeilen versehen, dass dieses Pfeilmuster in keinem Turnier häufiger vorkommt, als es in einem rein zufälligen Turnier zu erwarten ist (Anteil höchstens 2 hoch minus Kantenzahl).

### WikiB-2
Pfad: FormalConjectures/Wikipedia/RefactorableNumber.lean
Deklaration: zelinsky_refactorable_progression_conjecture, Zeile 75 (Attribut; `theorem` in Zeile 76)
Quelle: J. Zelinsky, „Tau Numbers: A Partial Proof of a Conjecture and Other Results“, Journal of Integer Sequences 5 (2002), Article 02.2.8, Conjecture 32, https://cs.uwaterloo.ca/journals/JIS/VOL5/Zelinsky/zelinsky9.pdf
Aussage: Eine Zahl heißt refaktorisierbar (Tau-Zahl), wenn die Anzahl ihrer Teiler sie teilt; Beispiel 12 hat sechs Teiler, und 6 teilt 12. Die Vermutung sagt: Kommt in einer Zahlenfolge mit festem Abstand (etwa 8, 13, 18, 23, …) eine solche Zahl vor, dann kommen darin unendlich viele vor.

### Sammel-1
Pfad: FormalConjectures/Other/EquationalTheories_677_255.lean
Deklaration: Finite.Equation677_implies_Equation255, Zeile 67 (Markierung Zeile 66)
Quelle: Equational Theories Project, Abschlussbericht arXiv:2512.07087, dort das einzige ungelöste Problem zur endlichen Implikation E677 ⊨_fin E255; Blueprint-Kapitel 13 https://teorth.github.io/equational_theories/blueprint/677-chapter.html
Aussage: Ein „Magma“ ist eine Menge mit einer beliebigen Verknüpfungstafel x◇y. Gefragt ist, ob in jeder endlichen Tafel, in der immer x = y◇(x◇((y◇x)◇y)) gilt, automatisch auch immer x = ((x◇x)◇x)◇x gilt.

### Sammel-2
Pfad: FormalConjectures/Kourovka/20_51.lean
Deklaration: kourovka_20_51, Zeile 37 (Markierung Zeile 36)
Quelle: Kourovka Notebook, Problem 20.51 (D. MacHale), https://arxiv.org/abs/1401.0300
Aussage: Die Elemente einer endlichen Gruppe zerfallen in sogenannte Konjugationsklassen. Gefragt ist, ob es zu jeder ungeraden Zahl t größer als 3 eine nicht kommutative Gruppe mit ungerade vielen Elementen gibt, die genau t solche Klassen hat.

### Sammel-3
Pfad: FormalConjectures/OpenQuantumProblems/35.lean
Deklaration: ame_8_4_open, Zeile 794 (Markierung Zeile 793)
Quelle: Open Quantum Problems, Problem 35, https://oqp.iqoqi.oeaw.ac.at/existence-of-absolutely-maximally-entangled-pure-states ; Tabelle von Huber und Wyderka, https://huberfe.github.io/ame
Aussage: Ein Quantenzustand aus mehreren Teilchen heißt absolut maximal verschränkt, wenn jede Hälfte der Teilchen für sich betrachtet völlig zufällig aussieht. Gefragt ist, ob es einen solchen Zustand für acht Teilchen mit je vier Einstellmöglichkeiten gibt.

### Green-1
Pfad: FormalConjectures/GreensOpenProblems/24.lean
Deklaration: Green24.variants.conjecture (im Index „conjecture“), Zeile 91
Quelle: Ben Green, „100 open problems“, Problem 24, https://people.maths.ox.ac.uk/greenbj/papers/open-problems.pdf#problem.24 ; die Vermutung γ = 1/3 bei J. Aaronson, „Maximising the number of solutions to a linear equation in a set of integers“, Bull. LMS 51 (2019) 577–594, https://arxiv.org/abs/1801.07135
Aussage: In einer Menge von n ganzen Zahlen zählt man alle Tripel der Form x, x+d, x+3d mit d ≠ 0 (verschobene und gestreckte Kopien von {0,1,3}). Behauptet wird, dass der größtmögliche Anteil solcher Tripel an n² für wachsendes n gegen genau 1/3 geht, dass also ein Intervall asymptotisch nicht zu schlagen ist.

### Green-2
Pfad: FormalConjectures/GreensOpenProblems/28.lean
Deklaration: Green28.green_28, Zeile 51 (Polynomfassung als zweiter Eintrag: FormalConjectures/Mathoverflow/339137.lean, mathoverflow_339137)
Quelle: Ben Green, „100 open problems“, Problem 28, https://people.maths.ox.ac.uk/greenbj/papers/open-problems.pdf#problem.28 ; ursprünglich https://mathoverflow.net/questions/339137 ; in der Literatur „unfair 0–1 polynomial conjecture“
Aussage: X und Y seien unabhängige ganzzahlige Zufallsgrößen mit endlich vielen Werten, und die Summe X+Y sei auf ihrem Wertebereich gleichverteilt. Müssen dann auch X und Y jeweils gleichverteilt sein? Gleichwertig: Hat das Produkt zweier normierter Polynome mit nichtnegativen reellen Koeffizienten nur Koeffizienten 0 und 1, haben dann schon beide Faktoren nur Koeffizienten 0 und 1?
