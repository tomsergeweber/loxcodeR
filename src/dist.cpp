/**
 * LoxcodeR
 * Cassette distances
 */

#include <Rcpp.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <tuple>
#include <fstream>
#include <cassert>
#include "pack.h"
#include "cassutil.h"

#define REC_MAX 15
#define FLOAT_SIZE 4

using namespace Rcpp;

// oooo global variables :(((
int size_to_size_idx[] = {-1, -1, -1, 4, -1, 3, -1, 2, -1, 1, -1, -1, -1, 0};

class distmaps{
  public:
    static ifstream* origin_files[5]; // files from the origin (organised by size_idx)
    static ifstream* pair_files[2]; // only supports 13 (size_idx = 0) and 9 (size_idx = 1) cassettes
    // probability of generation, first index specifies the size_idx and second
    // index specifies the recombination number.
    static ifstream* prob_files[5][15];

    static bool initialised;
    static bool initialised_pair;
    static bool initialised_prob[5][15];

    static void load_origin_files(std::vector<std::string> paths){
//      if(initialised){
//        cerr << __FUNCTION__ << ": already initialised!" << endl;
//        Rcpp::stop("Already initialised");
//      }
      if(paths.size() != 5){
         // cerr << __FUNCTION__ << ": paths.size() was not 5! missing some distance maps..." << endl;
         Rcpp::stop("Missing files");
      }
      for(int size_idx = 0; size_idx < paths.size(); size_idx++){
        distmaps::origin_files[size_idx] = new ifstream(paths[size_idx].c_str());
        // if(!distmaps::origin_files[size_idx]->is_open()){
        //   cerr << __FUNCTION__ << ": WARNING: failed to open file for size_idx = " << size_idx << ", path = " << paths[size_idx] << endl;
        // }
      }
      initialised = true;
    }

    static void load_pair_files(std::vector<std::string> paths){
//      if(initialised_pair){
//        cerr << __FUNCTION__ << ": already initialised pair!" << endl;
//        Rcpp::stop("Already initialised");
//      }
      if(paths.size() != 2){
        // cerr << __FUNCTION__ << ": paths.size() was not 2! missing some distance maps..." << endl;
        Rcpp::stop("Missing files");
      }
      for(int size_idx = 0; size_idx <= 1; size_idx++){
        distmaps::pair_files[size_idx] = new ifstream(paths[size_idx].c_str());
        // if(!distmaps::pair_files[size_idx]->is_open()){
        //   cerr << __FUNCTION__ << ": WARNING: failed to open file for size_idx = " << size_idx << ", path = " << paths[size_idx] << endl;
        // }
      }
      initialised_pair = true;
    }

    static void load_prob_files(std::vector<std::vector<std::string> >  paths){
      // paths[i][j] specifies the table for size_idx i and rec_idx j
      if(paths.size() != 5){
        // cerr << __FUNCTION__ << ": paths.size() inappropriate! missing some probability tables..." << endl;
        Rcpp::stop("Missing files");
      }
      for(int size_idx = 0; size_idx < 5; size_idx++){
        for(int n_rec = 0; n_rec < REC_MAX; n_rec++){
          if(paths[size_idx].size() <= n_rec){
            // skip this table
            prob_files[size_idx][n_rec] = NULL;
            initialised_prob[size_idx][n_rec] = false;
          }else{
            // otherwise load as usual
            distmaps::prob_files[size_idx][n_rec] = new ifstream(paths[size_idx][n_rec].c_str());
            if(!distmaps::prob_files[size_idx][n_rec]->is_open()){
              initialised_prob[size_idx][n_rec] = false;
              // cout << "table: size_idx = " << size_idx << " n_rec = " << n_rec << " skipped" << endl;
            }else{
              initialised_prob[size_idx][n_rec] = true;
              // cout << "table: size_idx = " << size_idx << " n_rec = " << n_rec << " loaded" << endl;
            }
          }
        }
      }

    }

    static unsigned char read_origin(long long offset, int size_idx){
      assert(size_idx < 5 && size_idx >= 0);
      assert(initialised);
      origin_files[size_idx]->seekg(offset);
      return origin_files[size_idx]->get();
    }

    static unsigned char read_pair(long long offset, int size_idx){
      assert(size_idx == 0 || size_idx == 1);
      assert(initialised_pair);
      pair_files[size_idx]->seekg(offset);
      return pair_files[size_idx]->get();
    }

    static float read_prob(long long offset, int size_idx, int rec_idx){
      assert(size_idx <= 5 && size_idx >= 0);
      assert(initialised_prob[size_idx][rec_idx]);
      float retv = 0;
      assert(sizeof(retv) == FLOAT_SIZE); // kind of important
      prob_files[size_idx][rec_idx]->seekg(offset*FLOAT_SIZE);
      prob_files[size_idx][rec_idx]->read((char*)&retv, FLOAT_SIZE);
      return retv;
    }

    ~distmaps(){
      if(initialised){
        for(int i = 0; i < 5; i++) delete origin_files[i];
        // cerr << __FUNCTION__ << ": closed distance table files" << endl;
        initialised = false;
      }
    }

  private:
    distmaps() {}
};

ifstream* distmaps::origin_files[5] = {NULL};
ifstream* distmaps::pair_files[2] = {NULL};
ifstream* distmaps::prob_files[5][15] = {NULL};


bool distmaps::initialised = false;
bool distmaps::initialised_pair = false;
bool distmaps::initialised_prob[5][15] = {{false}};



// [[Rcpp::export]]
void load_origin_files_wrapper(std::vector<std::string> paths){ distmaps::load_origin_files(paths); }

// [[Rcpp::export]]
void load_pair_files_wrapper(std::vector<std::string> paths){ distmaps::load_pair_files(paths); }

// [[Rcpp::export]]
void load_prob_files_wrapper(std::vector<std::vector<std::string> > paths){ distmaps::load_prob_files(paths); }


// [[Rcpp::export]]
void wrapper_fill_tables(){
  // wrapper
  fill_tables();
  // cerr << __FUNCTION__ << ": tables filled" << endl;
}

int get_size_idx(int size){
  return (size > 13 || size < 0) ? -1 : size_to_size_idx[size];
}

std::tuple<std::vector<int>, std::vector<int>, std::vector<int> > get_oes(std::vector<int>& k){
  std::vector<int> o(k.size()/2 + 1);
  std::vector<int> e(k.size()/2);
  std::vector<int> s(k.size());
  for(int i = 0; i < k.size(); i++){
     if(i % 2 == 0) o[i/2] = (abs(k[i])-1)/2; // odd elt
     else e[i/2] = (abs(k[i])/2)-1;

     s[i] = k[i] < 0 ? 1 : 0;
  }
  return std::make_tuple(o, e, s);
}

long long pack_single(std::vector<int> c, int size_idx){
  std::tuple<std::vector<int>, std::vector<int>, std::vector<int> > p = get_oes(c);
  long long packed = pack(pack_odd(&(std::get<0>(p))[0], size_idx),
                          pack_even(&(std::get<1>(p))[0], size_idx),
                          pack_sign(&(std::get<2>(p))[0], size_idx), size_idx);
  return packed;
}

template<typename T>
std::vector<long long> pack_impl(T c, std::vector<bool> v){ return std::vector<long long>(); /* DO NOT USE */ }

template<>
std::vector<long long> pack_impl(std::vector<std::vector<int> > c, std::vector<bool> v){
  std::vector<long long> out(c.size());
  for(int i = 0; i < c.size(); ++i){
    if(v[i] == false){ out[i] = NA_INTEGER;  continue;  }
    int size_idx = get_size_idx(c[i].size());
    if(size_idx != -1){
      out[i] = pack_single(c[i], size_idx);
    }else{
      out[i] = NA_INTEGER;
    }
  }
  return out;
}

template<>
std::vector<long long> pack_impl(std::vector<std::string> c, std::vector<bool> v){
  std::vector<std::vector<int> > c_int = get_cass_vec(c);
  return pack_impl(c_int, v);
}

//' Pack cassettes into cassette ID
//'
//' @param c a list of numeric vectors, or a character vector of decoded loxcodes
//' @param v vector of bool, output from validate()
//' @return cassettes with cassette id
//' @export
//' @examples
//' # Example usage:
//' # Assuming 'cassette' is a list of numeric vectors representing the cassette,
//' # 'validity_vector' is a vector of boolean values indicating the validity of each cassette.
//' # Pack the cassettes into cassette IDs
//' datards <- system.file("extdata","data-2024-05-20.rds",package="loxcodeR")
//' lox <- readRDS(datards)
//' # cassettes_with_ID <- pack(cassette, validity_vector)
//' # cassettes_with_ID
// [[Rcpp::export]]
std::vector<long long> pack(SEXP c, std::vector<bool> v){
  switch(TYPEOF(c)){
    case VECSXP:
      return pack_impl<std::vector<std::vector<int> > >(as<std::vector<std::vector<int> > >(c), v);
      break;
    case STRSXP:
      return pack_impl<std::vector<std::string> >(as<std::vector<std::string> >(c), v);
      break;
  }
  return std::vector<long long>();
}

//' Assumes that input cassette is valid already!
//'
//' @param c input cassette
//' @param size size of single loxcode
//' @return distance from origin
//' @export
//' @examples
//' # Example usage:
//' # Assuming 'cassette' is a valid input cassette and 'loxcode_size' is the size of a single loxcode.
//' # Calculate the distance from the origin
//' datards <- system.file("extdata","data-2024-05-20.rds",package="loxcodeR")
//' lox <- readRDS(datards)
//' #dist_from_origin <- retrieve_dist_origin_single(cassette, loxcode_size)
//' #dist_from_origin
// [[Rcpp::export]]
int retrieve_dist_origin_single(long long c, int size){
  if(!distmaps::initialised){
     Rcpp::stop("Not initialised");
  }
  return (int)distmaps::read_origin(c, get_size_idx(size))-1;
}

//' Assumes that input cassette is valid already!
//'
//' @param c input cassette
//' @param sizes sizes of all loxcode
//' @return distance from origin
//' @export
//' @examples
//' # Example usage:
//' # Assuming 'cassette' is a valid input cassette and 'loxcode_sizes' is a vector containing sizes of all loxcodes.
//' # Calculate the distance from the origin
//' datards <- system.file("extdata","data-2024-05-20.rds",package="loxcodeR")
//' lox <- readRDS(datards)
//' #dist_from_origin <- retrieve_dist_origin(cassette, loxcode_sizes)
//' #dist_from_origin
// [[Rcpp::export]]
std::vector<int> retrieve_dist_origin(std::vector<long long> c, std::vector<int> sizes){
  std::vector<int> out(c.size());
  if(!distmaps::initialised){
     Rcpp::stop("Not initialised");
  }
  for(int i = 0; i < c.size(); i++){
    if(c[i] != NA_INTEGER){
      // -1 indicates invalid cassette value. If not -1 then we assume that sizes is sensible...
      // must first call is_valid and pack beforehand!
//      out[i] = (int)distmaps::read_origin(c[i], get_size_idx(sizes[i]))-1; // don't forget to subtract 1
        out[i] = retrieve_dist_origin_single(c[i], sizes[i]);
    }else{
      out[i] = NA_INTEGER; // -1 for missing values
    }
  }
  return out;
}


//' Assumes that input cassette is valid already!
//'
//' @param c input cassette
//' @param sizes sizes of all loxcode
//' @param nrec position in cassette
//' @return Probability of a cassette
//' @export
//' @examples
//' # Example usage:
//' # Assuming 'cassette' is a valid input cassette, 'loxcode_sizes' is a vector containing sizes of all loxcodes,
//' # and 'position' is the position in the cassette.
//' # Calculate the probability of the cassette at the given position
//' datards <- system.file("extdata","data-2024-05-20.rds",package="loxcodeR")
//' lox <- readRDS(datards)
//' #cassette_prob <- retrieve_prob(cassette, loxcode_sizes, position)
//' #cassette_prob
// [[Rcpp::export]]
std::vector<float> retrieve_prob(std::vector<long long> c, std::vector<int> sizes, std::vector<int> nrec){
  std::vector<float> out(c.size());
  for(int i = 0; i < c.size(); i++){
    int size_idx = get_size_idx(sizes[i]);
    if(c[i] != NA_INTEGER && size_idx != -1 && nrec[i] >= 0 && nrec[i] <= 15){
      if(nrec[i] == 0){
        // special case, nrec == 0 means we are at origin
        out[i] = 1;
      }else{
        // not at origin
        if(distmaps::initialised_prob[size_idx][nrec[i]-1]){ /* subtract 1 because we are indexing */
          out[i] = distmaps::read_prob(c[i], size_idx, nrec[i]-1);
        }else{
          out[i] = R_NaN;
        }
      }
    }else{
      out[i] = R_NaN;
    }
  }
  return out;
}

int sign(int x){ return x > 0 ? 1 : -1; }

std::vector<int> transform_13(std::pair<std::vector<int>, std::vector<int> > c){
  std::map<int, int> elt_map;
  for(int i = 0; i < 13; i++){
    elt_map[abs(c.first[i])] = sign(c.first[i])*(i+1);
  }
  std::vector<int> out(13);
  for(int i = 0; i < 13; i++){
    out[i] = sign(c.second[i])*elt_map[abs(c.second[i])];
  }
  return out;
}

std::vector<int> transform_9(std::pair<std::vector<int>, std::vector<int> > c){
  // transform 9-element cassettes
  // transforms first cassette to 1-9, and second cassette relative to 1-9.
  std::map<int, int> elt_map;
  std::set<int> unseen_elts_e = {2, 4, 6, 8, 10, 12};
  std::set<int> unseen_elts_o = {1, 3, 5, 7, 9, 11, 13};
  for(int i = 0; i < 9; i++){
    elt_map[i+1] = c.first[i];
    if((i+1) % 2 == 1){
      // odd element
      unseen_elts_o.erase(abs(c.first[i]));
    }else{
      // even element
      unseen_elts_e.erase(abs(c.first[i]));
    }
  }
  // by this point, unseen_elts contains the 4 elements not seen in c[i]
  for(int i = 9; i < 13; i++){
    if((i+1) % 2 == 1){
      // odd element
      elt_map[i+1] = *unseen_elts_o.begin();
      unseen_elts_o.erase(unseen_elts_o.begin());
    }else{
      // even element
      elt_map[i+1] = *unseen_elts_e.begin();
      unseen_elts_e.erase(unseen_elts_e.begin());
    }
  }
  // now flip map
  std::map<int, int> rev_map;
  for(int i = 0; i < 13; i++){
    rev_map[abs(elt_map[i+1])] = sign(elt_map[i+1])*(i+1);
  }
  vector<int> out(9);
  for(int i = 0; i < 9; i++){
    out[i] = rev_map[abs(c.second[i])]*sign(c.second[i]);
  }
  return out;
}

std::vector<int> transform_13_9_pair(std::pair<std::vector<int>, std::vector<int> > c){
  // first argument is a 13-elt cassette, and second argument is a 9-elt cassette
  // transforms the 13-elt cassette to origin, and returns the corresponding 9-elt cassette

  std::map<int, int> elt_map; // keys are elements of c.first, values are the corresponding elements of the transformed cassette
  if(c.first.size() != 13 || c.second.size() != 9){
    // cerr << __FUNCTION__ << ": argument error" << endl;
    Rcpp::stop("Argument error");
  }
  for(int i = 0; i < c.first.size(); i++){
    elt_map[abs(c.first[i])] = sign(c.first[i])*(i+1);
  }
  // map is now set up
  std::vector<int> out(9);
  for(int i = 0; i < c.second.size(); i++){
    out[i] = elt_map[abs(c.second[i])]*sign(c.second[i]);
  }
  return out;
}

//' Assumes that input cassette is valid already!
//'
//' @param c1 input cassette 1
//' @param c2 input cassette 2
//' @return distance between 2 cassette
//' @export
//' @examples
//' # Example usage:
//' # Assuming 'cassette1' and 'cassette2' are valid input cassettes.
//' # Calculate the distance between the two cassettes
//' datards <- system.file("extdata","data-2024-05-20.rds",package="loxcodeR")
//' lox <- readRDS(datards)
//' #dist_between_cassettes <- retrieve_dist_pair(cassette1, cassette2)
//' #dist_between_cassettes
// [[Rcpp::export]]
Rcpp::NumericMatrix retrieve_dist_pair(std::vector<std::vector<int> > c1, std::vector<std::vector<int> > c2){
  /*if(size != 13 && size != 9){
    // only support distance pairs for size 9 and 13
    cerr << __FUNCTION__ << ": pairwise distance supported only for cassettes of size 13, 9" << endl;
    Rcpp::stop("Not supported");
  }*/

  if(!distmaps::initialised){
     Rcpp::stop("Not initialised");
  }
  Rcpp::NumericMatrix out(c1.size(), c2.size());
  for(int i = 0; i < c1.size(); i++){
    for(int j = 0; j < c2.size(); j++){
      if(c1[i].size() == c2[j].size()){
        // both cassettes are of the same size
        int size = c1[i].size();
        int size_idx = get_size_idx(size);
        if(size == 13){
          std::vector<int> x = transform_13(std::make_pair(c1[i], c2[j]));
          long long x_packed = pack_single(x, 0);
          int dist = distmaps::read_pair(x_packed, 0)-1;
          out(i, j) = dist;
        }else if(size == 9){
          std::vector<int> x = transform_9(std::make_pair(c1[i], c2[j]));
          long long x_packed = pack_single(x, 1);
          int dist = distmaps::read_pair(x_packed, 1)-1;
          out(i, j) = dist;
        }else{
          // unrecognized size
          // cerr << __FUNCTION__ << ": pairwise distance supported only for cassettes of size 13, 9" << endl;
          Rcpp::stop("Not supported");
        }
      }else{
        // not the same size
        // handle the case where one code is 9-element and the other is 13-element
        std::vector<int> x;
        if(c1[i].size() == 9 && c2[j].size() == 13) x = transform_13_9_pair(std::make_pair(c2[j], c1[i]));
        else if(c1[i].size() == 13 && c2[j].size() == 9) x = transform_13_9_pair(std::make_pair(c1[i], c2[j]));
        else{
          // unrecognized size
          // cerr << __FUNCTION__ << ": pairwise distance supported only for cassettes of size 13, 9" << endl;
          Rcpp::stop("Not supported");
        }

        // now lookup
        long long x_packed = pack_single(x, 1);
        int dist = (int)distmaps::read_origin(x_packed, 1)-1;
        out(i, j) = dist;
      }
    }
  }
  return out;
}

