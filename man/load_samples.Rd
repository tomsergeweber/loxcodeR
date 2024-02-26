% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/loxcode_experiment.R
\name{load_samples}
\alias{load_samples}
\title{Load data from FASTQ for all samples in a loxcode_experiment object}
\usage{
load_samples(x, ...)
}
\arguments{
\item{x}{loxcode_experiment object for which to load samples}

\item{full}{boolean, whether to produce full debugging output (default is FALSE, this uses significantly more memory)}
}
\value{
loxcode_experiment object with sample data loaded
}
\description{
For each sample in the loxcode_experiment, barcodes readout is performed from FASTQ
followed by element imputation for the 13-element codes. Loxcodes are then validated, IDs fetched,
and distance-from-origin is retrieved.
}